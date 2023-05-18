#pragma once
#ifndef LETTERGAME_H
#define LETTERGAME_H

#include <string>
#include <array>
#include <iostream>

const int MAX_WORDS = 100; // максимальное количество слов в файле

class LetterGame {
public:
    LetterGame(const std::array<std::string, MAX_WORDS>& wordList, int wordCount);
    void startNewGame();
    bool checkGuess(const std::string& guess);
    void printHint(std::string userWord) const;
    bool isGameOver() const;
    std::string getSecretWord() const;
    int getAttemptCount() const;

private:
    std::string generateSecretWord();

    std::array<std::string, MAX_WORDS> wordList;
    int wordCount;
    std::string secretWord;
    int attemptCount;
    bool gameOver;
};

#endif  // LETTERGAME_H
