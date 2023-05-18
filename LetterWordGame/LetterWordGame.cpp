#include "LetterGame.h"

#include <fstream>
#include <ctime>

int main() {
    system("chcp 1251>nul");
    // Чтение слов из файла
    std::ifstream inputFile("words.txt");
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    std::string word;
    std::array<std::string, MAX_WORDS> words;
    int wordCount = 0;
    while (inputFile >> word && wordCount < MAX_WORDS) {
        words[wordCount++] = word;
    }

    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Создание объекта игры
    LetterGame game(words, wordCount);

    char choice;
    do {
        // Начало новой игры
        game.startNewGame();

        // Игровой цикл
        while (!game.isGameOver()) {
            std::cout << "Попытка " << game.getAttemptCount() << ": ";
            std::string guess;
            std::cin >> guess;

            if (guess.length() != 6) {
                std::cout << "Некорректное слово. Введите слово из 6 букв." << std::endl;
                continue;
            }

            bool result = game.checkGuess(guess);
            if (result) {
                std::cout << "Вы угадали слово! Поздравляем!" << std::endl;
                break;
            }
            else {
                std::cout << "Неверное слово. ";
                game.printHint(guess);
            }

            if (game.isGameOver()) {
                std::cout << "Игра окончена. Загаданное слово: " << game.getSecretWord() << std::endl;
            }
        }

        // Запрос на рестарт или выход
        std::cout << "Введите R для рестарта или Q для выхода: ";
        std::cin >> choice;
        choice = std::toupper(choice);
    } while (choice != 'Q');

    return 0;
}