#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

int main() {

    setlocale(0, "Rus");

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;// сглаживание
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Application", sf::Style::Default, settings );
    
    float storona;
    float speedygonzales;
    cout << "¬ведите сторону правильного треугольника : " << endl;
    cin >>  storona;
    cout << "¬ведите скорость вращени€ : " << endl;
    cin >> speedygonzales;
    float tick = 1;

    RectangleShape rectangle;
    rectangle.setFillColor(Color::Cyan);
    rectangle.setSize(Vector2f(100.f, 50.f));
    rectangle.setOrigin(50.f, 25.f);

    CircleShape circle;
    circle.setFillColor(Color::Red);
    circle.setRadius(5.f);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    circle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    CircleShape triangle(storona, 3);
    triangle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    triangle.setFillColor(sf::Color::Green);
    triangle.setOrigin(triangle.getRadius(), triangle.getRadius());
    triangle.setRotation(tick);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
            triangle.move(-10.f, 0.f);

            
        if (Keyboard::isKeyPressed(Keyboard::D))
            triangle.move(10.f, 0.f);

        if (Keyboard::isKeyPressed(Keyboard::W))
            triangle.move(0.f, -10.f);
          
            
        if (Keyboard::isKeyPressed(Keyboard::S))
            triangle.move(0.f, 10.f);

        if (Keyboard::isKeyPressed(Keyboard::S))
            circle.move(0.f, 10.f);
        if (Keyboard::isKeyPressed(Keyboard::A))
            circle.move(-10.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::D))
            circle.move(10.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::W))
            circle.move(0.f, -10.f);
            
        if (Keyboard::isKeyPressed(Keyboard::R))
            triangle.rotate(speedygonzales);

        /*sf::Vector2i mp = sf::Mouse::getPosition(window);
        x0 = mp.x;
        y0 = mp.y;*/


        

        window.clear();
        
        
        window.draw(triangle);

        window.draw(rectangle);
        window.draw(circle);
        window.display();

        sf::sleep(sf::milliseconds(10));
        tick++;
    }

}

