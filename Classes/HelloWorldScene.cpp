#define COCOS2D_DEBUG 1

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    MenuItemImage* closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    Menu* menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    Label* label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    Sprite* sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    

	*/
    // CUSTOM:

    CCLOG("___visibleSize: %f / %f", visibleSize.width, visibleSize.height);
    CCLOG("___contentSize: %f / %f", this->getContentSize().width, this->getContentSize().height);

    SpriteFrameCache* spriteCache = SpriteFrameCache::getInstance();
    spriteCache->addSpriteFramesWithFile("crappyturdssprites.plist");

    SpriteFrame* bordertopFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("bordertop.png");
    SpriteFrame* borderbottomFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("borderbottom.png");

    Sprite *topBorder = Sprite::createWithSpriteFrame(bordertopFrame);
    Sprite *topBorder2 = Sprite::createWithSpriteFrame(bordertopFrame);
    Sprite *topBorder3 = Sprite::createWithSpriteFrame(bordertopFrame);
    Sprite *bottomBorder = Sprite::createWithSpriteFrame(borderbottomFrame);
    Sprite *bottomBorder2 = Sprite::createWithSpriteFrame(borderbottomFrame);
    Sprite *bottomBorder3 = Sprite::createWithSpriteFrame(borderbottomFrame);

    topBorder->setAnchorPoint(Vec2(0,1));
    topBorder->setPosition(Vec2(0,480));
    topBorder2->setAnchorPoint(Vec2(0,1));
    topBorder2->setPosition(Vec2( topBorder->getContentSize().width - 1, 480));
    topBorder3->setAnchorPoint(Vec2(0,1));
    topBorder3->setPosition(Vec2( (topBorder->getContentSize().width * 2) - 2, 480));

    bottomBorder->setAnchorPoint(Vec2(0,0));
    bottomBorder->setPosition(Vec2(0,0));
    bottomBorder2->setAnchorPoint(Vec2(0,0));
    bottomBorder2->setPosition(Vec2(bottomBorder->getContentSize().width - 2, 0));
    bottomBorder3->setAnchorPoint(Vec2(0,0));
    bottomBorder3->setPosition(Vec2( (bottomBorder->getContentSize().width * 2) - 4, 0));



    this->addChild(bottomBorder);
    this->addChild(bottomBorder2);
    this->addChild(bottomBorder3);
    this->addChild(topBorder);
    this->addChild(topBorder2);
    this->addChild(topBorder3);



    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
