#include "PersonKeeper.h"
#include "person.h"

PersonKeeper& PersonKeeper::instance()
{
    static PersonKeeper keeper;
    return keeper;
}

// Записывает из Стека в файл
void PersonKeeper::writePersons(Stack<Person> stack, std::fstream& ofile)
{
    if (!ofile) // Если файл не открылся
    {
            throw std::runtime_error("Error writing file. File not found\n"); // Выбрасываем исключение
    }

    for (unsigned i = 0; i < stack.getSize(); i++) // Идём по элементам стэка
    {
        int j =0; // чтоб грамотно выводить новую строку
        if (!(stack[i].getLastName().empty()))
        {
            ofile << stack[i].getLastName(); // Выводим в файл Фамилию
            ofile << ' ';
            j++;
        }

        if(!(stack[i].getFirstName().empty()))
        {
            ofile << stack[i].getFirstName(); // Выводим в файл Имя
            ofile << ' ';
            j++;
        }

        if(!(stack[i].getPatronymic().empty()))
        {
            ofile << stack[i].getPatronymic();// Выводим в файл Отчество
            j++;
        }

        if(j != 0) // Если никакие данные не прошли, то новая строка не нужна
        {
            ofile << '\n';
        }
    }
}

// Считывает ФИО из файла в Стек
Stack<Person> PersonKeeper::readPersons(std::fstream& ifile)
{
    if (!ifile) // Если файл не открылся
    {
            throw std::runtime_error("Error reading file. File not found\n"); // Выбрасываем исключение
    }

    Stack<Person> stack;
    std::string string_;

    while (std::getline(ifile, string_)) // Пока мы можем брать строку из файла
    {
        stack.push(Person(string_)); // Кладём в Стек персону
    }

    return stack;
}
