#include "LetterGame.h"

LetterGame::LetterGame(const std::array<std::string, MAX_WORDS>& wordList, int wordCount)
    : wordList(wordList), wordCount(wordCount), attemptCount(0), gameOver(false) {}

void LetterGame::startNewGame() {
    attemptCount = 0;
    gameOver = false;
    secretWord = generateSecretWord();
}

bool LetterGame::checkGuess(const std::string& userWord) {
    ++attemptCount;

    if (userWord == secretWord) {
        gameOver = true;
        return true;
    }

    return false;
}

void LetterGame::printHint(std::string& userWord) const {
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == userWord[i]) {
            std::cout << "(" << userWord[i] << ")";
        }
        else if (secretWord.find(userWord[i]) != std::string::npos) {
            std::cout << "[" << userWord[i] << "]";
        }
        else {
            std::cout << userWord[i];
        }
    }
    std::cout << std::endl;
}

bool LetterGame::isGameOver() const {
    return gameOver || attemptCount >= 6;
}

std::string LetterGame::getSecretWord() const {
    return secretWord;
}

int LetterGame::getAttemptCount() const
{
    return attemptCount;
}

std::string LetterGame::generateSecretWord() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> wordDist(0, wordCount - 1);

    return wordList[wordDist(rng)];
}

