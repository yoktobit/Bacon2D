/**
 * The MIT License (MIT)
 *
 * Copyright (C) 2012 by INdT
 * Copyright (C) 2014 Bacon2D Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @author Rodrigo Goncalves de Oliveira <rodrigo.goncalves@openbossa.org>
 * @author Roger Felipe Zanoni da Silva <roger.zanoni@openbossa.org>
 */

#include "plugins.h"

#include "entity.h"
#include "enums.h"
#include "scene.h"
#include "spriteanimation.h"
#include "sprite.h"
#include "imagelayer.h"
#include "game.h"
#include "viewport.h"
#include "behavior.h"
#include "scriptbehavior.h"
#include "settings.h"

#include "box2dworld.h"
#include "box2dbody.h"
#include "box2ddebugdraw.h"
#include "box2dfixture.h"
#include "box2djoint.h"
#include "box2ddistancejoint.h"
#include "box2dprismaticjoint.h"
#include "box2drevolutejoint.h"
#include "box2dmotorjoint.h"
#include "box2dweldjoint.h"
#include "box2dpulleyjoint.h"
#include "box2dfrictionjoint.h"
#include "box2dwheeljoint.h"
#include "box2dmousejoint.h"
#include "box2dgearjoint.h"
#include "box2dropejoint.h"
#include "box2draycast.h"
#include "box2dcontact.h"
#include "scrollbehavior.h"

void Plugins::registerTypes(const char *uri)
{
    Q_UNUSED(uri)

    qmlRegisterType<Layer>("harbour.minerminingmines", 1, 0, "Layer");
    qmlRegisterUncreatableType<Behavior>("harbour.minerminingmines", 1, 0, "Bacon2DBehavior", "Don't use Bacon2DBehavior directly, use one specialized behavior");
    qmlRegisterUncreatableType<Bacon2D>("harbour.minerminingmines", 1, 0, "Bacon2D", "Not creatable as an object, use only to access enums");

    qmlRegisterType<Game>("harbour.minerminingmines", 1, 0, "Game");
    qmlRegisterType<Scene>("harbour.minerminingmines", 1, 0, "Scene");
    qmlRegisterType<Entity>("harbour.minerminingmines", 1, 0, "Entity");
    qmlRegisterType<Sprite>("harbour.minerminingmines", 1, 0, "Sprite");
    qmlRegisterType<SpriteAnimation>("harbour.minerminingmines", 1, 0, "SpriteAnimation");
    qmlRegisterType<ImageLayer>("harbour.minerminingmines", 1, 0, "ImageLayer");
    qmlRegisterType<Viewport>("harbour.minerminingmines", 1, 0, "Viewport");
    qmlRegisterType<ScriptBehavior>("harbour.minerminingmines", 1, 0, "ScriptBehavior");
    qmlRegisterType<Settings>("harbour.minerminingmines", 1, 0, "Settings");
    qmlRegisterType<ScrollBehavior>("harbour.minerminingmines", 1, 0, "ScrollBehavior");

    qmlRegisterUncreatableType<Box2DWorld>("harbour.minerminingmines", 1, 0, "World",
                                           QStringLiteral("World created by Scene if physics is enabled"));
    qmlRegisterUncreatableType<Box2DBody>("harbour.minerminingmines", 1, 0, "Body",
                                          QStringLiteral("Body is the base class for Entity"));
    qmlRegisterUncreatableType<Box2DFixture>("harbour.minerminingmines", 1, 0, "Fixture",
                                             QStringLiteral("Base type for Box, Circle etc."));
    qmlRegisterType<Box2DBody>("harbour.minerminingmines", 1, 0, "Body");
    qmlRegisterType<Box2DBox>("harbour.minerminingmines", 1, 0, "Box");
    qmlRegisterType<Box2DCircle>("harbour.minerminingmines", 1, 0, "Circle");
    qmlRegisterType<Box2DPolygon>("harbour.minerminingmines", 1, 0, "Polygon");
    qmlRegisterType<Box2DChain>("harbour.minerminingmines", 1, 0, "Chain");
    qmlRegisterType<Box2DEdge>("harbour.minerminingmines", 1, 0, "Edge");
    qmlRegisterUncreatableType<Box2DDebugDraw>("harbour.minerminingmines", 1, 0, "DebugDraw",
                                               QStringLiteral("DebugDraw created by Scene if physics and debug is enabled"));
    qmlRegisterUncreatableType<Box2DJoint>("harbour.minerminingmines", 1, 0, "Joint",
                                           QStringLiteral("Base type for DistanceJoint, RevoluteJoint etc."));
    qmlRegisterType<Box2DDistanceJoint>("harbour.minerminingmines", 1, 0, "DistanceJoint");
    qmlRegisterType<Box2DPrismaticJoint>("harbour.minerminingmines", 1, 0, "PrismaticJoint");
    qmlRegisterType<Box2DRevoluteJoint>("harbour.minerminingmines", 1, 0, "RevoluteJoint");
    qmlRegisterType<Box2DMotorJoint>("harbour.minerminingmines", 1, 0, "MotorJoint");
    qmlRegisterType<Box2DWeldJoint>("harbour.minerminingmines", 1, 0, "WeldJoint");
    qmlRegisterType<Box2DPulleyJoint>("harbour.minerminingmines", 1, 0, "PulleyJoint");
    qmlRegisterType<Box2DFrictionJoint>("harbour.minerminingmines", 1, 0, "FrictionJoint");
    qmlRegisterType<Box2DWheelJoint>("harbour.minerminingmines", 1, 0, "WheelJoint");
    qmlRegisterType<Box2DMouseJoint>("harbour.minerminingmines", 1, 0, "MouseJoint");
    qmlRegisterType<Box2DGearJoint>("harbour.minerminingmines", 1, 0, "GearJoint");
    qmlRegisterType<Box2DRopeJoint>("harbour.minerminingmines", 1, 0, "RopeJoint");
    qmlRegisterType<Box2DRayCast>("harbour.minerminingmines", 1, 0, "RayCast");

    qmlRegisterUncreatableType<Box2DContact>("harbour.minerminingmines", 1, 0, "Contact", QStringLiteral("Contact class"));
}
