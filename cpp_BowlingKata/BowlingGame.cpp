#include "BowlingGame.h"

int BowlingGame::Score() {
  int scorePoints = 0, frameIndex = 0, frames = 10;
  for (int i = 0; i < frames; i++) {
    if (IsStrike(frameIndex)) {
      scorePoints += StrikeBonus(frameIndex);
      frameIndex += 1;
    } else if (IsSpare(frameIndex)) {
      scorePoints += SpareBonus(frameIndex);
      frameIndex += 2;
    } else {
      scorePoints += pinsRolled.at(frameIndex) + pinsRolled.at(frameIndex + 1);
      frameIndex += 2;
    }
  }

  return scorePoints;
}

void BowlingGame::Roll(int pinsDown) { pinsRolled.push_back(pinsDown); }

bool BowlingGame::IsSpare(int index) {
  return (pinsRolled[index] + pinsRolled[index + 1] == 10) ? true : false;
}

bool BowlingGame::IsStrike(int index) {
  return (pinsRolled[index] == 10) ? true : false;
}

int BowlingGame::SpareBonus(int index) {
  return (10 + pinsRolled.at(index + 2));
}

int BowlingGame::StrikeBonus(int index) {
  return (10 + pinsRolled.at(index + 1) + pinsRolled.at(index + 2));
}
