#include <vector>

class BowlingGame {

public:
  int Score();
  void Roll(int pinsDown = 0);

private:
  bool IsStrike(int index = 0);
  bool IsSpare(int index = 0);

  int SpareBonus(int index = 0);
  int StrikeBonus(int index = 0);

  std::vector<int> pinsRolled = {};
};
