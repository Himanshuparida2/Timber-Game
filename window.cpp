#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
using namespace sf;

int main()
{
    // Creating Video Mode Object
    VideoMode vm(1366, 768);
    // This Create and Open a Window For Game
    // RenderWindow Renders Our Window With Name of the Window
    RenderWindow window(vm, "Timber");

    // Texture
    Texture background;
    background.loadFromFile("graphics/background.png");

    // Sprite
    Sprite spriteBackground;
    spriteBackground.setTexture(background);
    spriteBackground.setPosition(-5, 0);
    spriteBackground.setScale(1.5, 1.5);

    // Putting The Bee
    Texture bee;
    Sprite spritebee;
    bee.loadFromFile("graphics/bee.png");
    spritebee.setTexture(bee);
    spritebee.setPosition(0, 600);
    bool beeActive = false;
    float beeSpeed = 300.0f;
    float beeRadius = 80.0f;
    float beeAngle = 0.0f;

    // Putting Cloud
    Texture cloud;
    Sprite spritecloud1, spritecloud2, spritecloud3;
    cloud.loadFromFile("graphics/cloud.png");
    spritecloud1.setTexture(cloud);
    spritecloud1.setPosition(0, 0);
    spritecloud1.setScale(0.5, 0.5);
    spritecloud2.setTexture(cloud);
    spritecloud2.setPosition(40, 40);
    spritecloud2.setScale(0.5, 0.5);
    spritecloud3.setTexture(cloud);
    spritecloud3.setPosition(80, 80);
    spritecloud3.setScale(0.5, 0.5);
    
    // Cloud Movement
    bool CLoudMove1 = false;
    bool CLoudMove2 = false;
    bool CLoudMove3 = false;
    
    // Cloud Speed
    float CloudSpeedValue1 = 0.0f;
    float CloudSpeedValue2 = 0.0f;
    float CloudSpeedValue3 = 0.0f;
    
    // Load font for the score
    Font font;
    if (!font.loadFromFile("graphics/font.ttf")) {
        // Handle error if font is not found
        return -1;
    }
    
    Clock clock;
    Time dt;
    
    //Time 
    Text time;
    time.setFont(font);
    time.setString("Timer: 0");
    time.setFillColor(Color::White);
    time.setCharacterSize(60);
    time.setPosition(1100, 20);

    // Putting Tree
    Texture tree;
    Sprite spritetree;
    tree.loadFromFile("graphics/tree.png");
    spritetree.setTexture(tree);
    spritetree.setPosition(570, 0);
    spritetree.setScale(0.8, 0.8);


    //Score 
    int score = 0;
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: 0");
    scoreText.setFillColor(Color::White);
    scoreText.setCharacterSize(60);
    scoreText.setPosition(20, 20);

    // Ready to start text
    Text readyText;
    readyText.setFont(font);
    readyText.setString("Ready to Start! \nPress Enter");
    readyText.setFillColor(Color::White);
    readyText.setCharacterSize(70);
    readyText.setPosition(500, 300);

    // Game Over text
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setCharacterSize(60);
    gameOverText.setPosition(400, 300);

    bool gameStarted = false;
    bool gameOver = false;
    float gameTime = 0.0f;  // Track the elapsed time

    while (window.isOpen())
    {
        dt = clock.restart();
        float dtSeconds = dt.asSeconds();

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && !gameStarted)
            {
                // Start the game when Enter is pressed
                gameStarted = true;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
            {
                // Update the score (for example, the bee might increase the score when passing a specific point)
                scoreText.setString("Score: " + std::to_string(score));
                score++;
            }
        }

        window.clear();
        
        // Game Logic (only if the game has started and not over)
        if (gameStarted && !gameOver) {
            // Increment the game time
            gameTime += dtSeconds;
            time.setString("Timer: "+std::to_string(gameTime));

            // Check if 1 minute has passed (60 seconds)
            if (gameTime >= 60.0f) {
                gameOver = true; // Set game over flag when 1 minute passes
            }

            // Making Bees Fly
            beeAngle += 180.0f * dtSeconds;
            if (beeAngle > 360.0f)
            {
                beeAngle -= 360.0f;
            }

            // Update bee's position based on angle
            float beeX = spritebee.getPosition().x - (beeSpeed * dtSeconds);
            float beeY = 300 + beeRadius * sin(beeAngle * 3.14f / 180.0f);
            spritebee.setPosition(beeX, beeY);

            // Reset bee when it goes off-screen
            if (spritebee.getPosition().x < -100)
            {
                spritebee.setPosition(2000, 300); // Start position for the bee
                beeAngle = 0;                     // Reset angle to start from initial position
            }

            // Cloud Movement Logic
            if (!CLoudMove1)
            {
                CloudSpeedValue1 = (rand() % 300) + 300;
                float height = (rand() % 150) + 50;
                spritecloud1.setPosition(1920, height);  // Start cloud1 off-screen on the right
                CLoudMove1 = true;
            }
            else
            {
                spritecloud1.setPosition(spritecloud1.getPosition().x - (CloudSpeedValue1 * dt.asSeconds()), spritecloud1.getPosition().y);
                if (spritecloud1.getPosition().x < -100)
                {
                    spritecloud1.setPosition(1920, spritecloud1.getPosition().y); // Reset to right side
                }
            }

            if (!CLoudMove2)
            {
                CloudSpeedValue2 = (rand() % 300) + 300;
                float height = (rand() % 150) + 50;
                spritecloud2.setPosition(1920, height);  // Start cloud2 off-screen on the right
                CLoudMove2 = true;
            }
            else
            {
                spritecloud2.setPosition(spritecloud2.getPosition().x - (CloudSpeedValue2 * dt.asSeconds()), spritecloud2.getPosition().y);
                if (spritecloud2.getPosition().x < -100)
                {
                    spritecloud2.setPosition(1920, spritecloud2.getPosition().y); // Reset to right side
                }
            }

            if (!CLoudMove3)
            {
                CloudSpeedValue3 = (rand() % 300) + 300;
                float height = (rand() % 150) + 50;
                spritecloud3.setPosition(1920, height);  // Start cloud3 off-screen on the right
                CLoudMove3 = true;
            }
            else
            {
                spritecloud3.setPosition(spritecloud3.getPosition().x - (CloudSpeedValue3 * dt.asSeconds()), spritecloud3.getPosition().y);
                if (spritecloud3.getPosition().x < -100)
                {
                    spritecloud3.setPosition(1920, spritecloud3.getPosition().y); // Reset to right side
                }
            }
        }

        window.clear();
        
        if (!gameStarted) {
            // Display the "Ready to Start" text before the game starts
            window.draw(spriteBackground);
            window.draw(spritetree);
            window.draw(readyText);
        } else if (gameOver) {
            // Display "Game Over" message when the time is up
            gameOverText.setString("Game Over! Time's up.\nScore : "+std::to_string(score));
            window.draw(spriteBackground);
            window.draw(spritetree);
            window.draw(gameOverText);
        } else {
            // Draw game elements while the game is running
            window.draw(spriteBackground);
            window.draw(spritebee);
            window.draw(spritecloud1);
            window.draw(spritecloud2);
            window.draw(spritecloud3);
            window.draw(spritetree);
            window.draw(scoreText);
            window.draw(time);
        }
        
        window.display();
    }

    return 0;
}