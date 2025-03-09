#include <SFML/Graphics.hpp>
using namespace sf;
int main(){
    //Creating Video Mode Object
    VideoMode vm(1920,1080);
    //This Create and Open a Window For Game
    //RenderWindow Renders Our Window With Name of the Window 
    RenderWindow window(vm,"Timber");

    //Texture
    Texture background;
    background.loadFromFile("graphics/background.png");

    //Sprite
    Sprite spriteBackground;
    spriteBackground.setTexture(background);
    spriteBackground.setPosition(0,0);
    spriteBackground.setScale(0.75,0.75);

    //Putting The Bee
    Texture bee;
    Sprite spritebee;
    bee.loadFromFile("graphics/bee.png");
    spritebee.setTexture(bee);
    spritebee.setPosition(0,600);
    bool beeActive=false;
    float beeSpeed=0.0f;

    //Putting Cloud
    Texture cloud;
    Sprite spritecloud1,spritecloud2,spritecloud3;
    cloud.loadFromFile("graphics/cloud.png");
    spritecloud1.setTexture(cloud);
    spritecloud1.setPosition(0,0);
    spritecloud1.setScale(0.5,0.5);
    spritecloud2.setTexture(cloud);
    spritecloud2.setPosition(0.5,0.5);
    spritecloud2.setScale(0.5,0.5);
    spritecloud3.setTexture(cloud);
    spritecloud3.setPosition(1,1);
    spritecloud3.setScale(0.5,0.5);
    
    while(window.isOpen()){
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        window.clear();
        window.draw(spriteBackground);
        window.draw(spritebee);
        window.draw(spritecloud1);
        window.draw(spritecloud2);
        window.draw(spritecloud3);
        window.display();
    }
    return 0;
}