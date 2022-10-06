#include <QCoreApplication>
#include <iostream>
#include "Stack.h"

int main()
{

    try
    {
        Stack<int> arr;
        std::cout<<"Razmer: "<<arr.getSize()<< std::endl;
        //std::cout<<"Top: "<<arr.topFunc()<< std::endl; // Вызов top в пустом стеке для проверки
        //arr.pop(); // Вызов pop в пустом стеке для проверки
        arr.push(3);
        std::cout<<"Size: "<<arr.getSize()<< std::endl;
        std::cout<<"Top: "<<arr.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        arr.push(5);
        std::cout<<"Size: "<<arr.getSize()<< std::endl;
        std::cout<<"Top: "<<arr.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        arr.push(9);
        std::cout<<"Size: "<<arr.getSize()<< std::endl;
        std::cout<<"Top: "<<arr.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        arr.push(2);
        std::cout<<"Size: "<<arr.getSize()<< std::endl;
        std::cout<<"Top: "<<arr.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
        arr.pop();
        std::cout<<"Size: "<<arr.getSize()<< std::endl;
        std::cout<<"Top: "<<arr.topFunc()<< std::endl;
        std::cout<<"-----------------------------------"<< std::endl;
    }
    catch (const exep_stack::EStackEmpty & e) //исключение - пустой стек
    {
        std::cout<< e.what();
    }

    return 0;
}
