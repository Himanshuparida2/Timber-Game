#include <SFML/Graphics.hpp>
using namespace sf;
int main(){
    //Creating Video Mode Object
    VideoMode vm(1920,1080);
    //This Create and Open a Window For Game
    //RenderWindow Renders Our Window With Name of the Window 
    RenderWindow window(vm,"Timber");
    
    while(window.isOpen()){
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
    }
    window.clear();
    window.display();
    return 0;
}