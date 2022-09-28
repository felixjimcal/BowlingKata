#include "BowlingGame.cpp"
#include <gtest/gtest.h>

namespace {

BowlingGame *game;

struct BowlingGameTest : testing::Test {
  BowlingGameTest() { game = new BowlingGame(); }
};

void RollMany(int rolls = 0, int pins = 0) {
  for (int i = 0; i < rolls; i++) {
    game->Roll(pins);
  }
}

void RollSpare(){
    RollMany(2, 5);
}

void RollStrike(){
    RollMany(1, 10);
}

}; // namespace

TEST_F(BowlingGameTest, SimpleGame) {
  // Arrange
  RollMany(20, 1);

  // Act
  int expectedResult = 20, actualResult = game->Score();

  // Result
  EXPECT_EQ(expectedResult, actualResult);
};

TEST_F(BowlingGameTest, SpareTo11Points) {
  // Arrange
  RollSpare();
  RollMany(1, 0);
  RollMany(1, 1);
  RollMany(17, 0);

  // Act
  int expectedResult = 11, actualResult = game->Score();

  // Result
  EXPECT_EQ(expectedResult, actualResult);
};


TEST_F(BowlingGameTest, SpareTo12Points) {
    // Arrange
    RollSpare();
    RollMany(1, 1);
    RollMany(1, 0);
    RollMany(17, 0);

    // Act
    int expectedResult = 12, actualResult = game->Score();

    // Result
    EXPECT_EQ(expectedResult, actualResult);
};

TEST_F(BowlingGameTest, StrikeTo12) {
    // Arrange
    RollStrike();
    RollMany(1, 1);
    RollMany(1, 0);
    RollMany(17, 0);

    // Act
    int expectedResult = 12, actualResult = game->Score();

    // Result
    EXPECT_EQ(expectedResult, actualResult);
};

TEST_F(BowlingGameTest, ThreeStrikes) {
    // Arrange
    RollStrike();
    RollStrike();
    RollStrike();
    RollMany(17, 0);

    // Act
    int expectedResult = 60, actualResult = game->Score();

    // Result
    EXPECT_EQ(expectedResult, actualResult);
};

TEST_F(BowlingGameTest, PerfectGame) {
    // Arrange
    RollMany(20, 10);

    // Act
    int expectedResult = 300, actualResult = game->Score();

    // Result
    EXPECT_EQ(expectedResult, actualResult);
};
