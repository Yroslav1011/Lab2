#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

int main() {
    // Инициализация генератора случайных чисел
    random_device rd;  // Источник энтропии
    mt19937 gen(rd()); // Вихрь Мерсенна (генератор)
    uniform_int_distribution<> distrib(1, 10); // Диапазон от 1 до 10 включительно

    // Массив с именами файлов
    string filenames[] = {"file1.txt", "file2.txt", "file3.txt"};

    // Цикл по всем трем файлам
    for (int i = 0; i < 3; ++i) {
        ofstream outFile(filenames[i]); // Открываем файл для записи

        if (!outFile.is_open()) {
            cerr << "Ошибка: не удалось создать файл " << filenames[i] << endl;
            return 1;
        }

        // Записываем 10 случайных чисел
        for (int j = 0; j < 10; ++j) {
            outFile << distrib(gen);
            if (j < 9) {
                outFile << " "; // Пробел между числами (но не после последнего)
            }
        }
        outFile << endl; // Перевод строки в конце
        outFile.close(); // Закрываем файл
        cout << "Файл " << filenames[i] << " успешно создан." << endl;
    }

    cout << "Все файлы сгенерированы!" << endl;
    return 0;
}
