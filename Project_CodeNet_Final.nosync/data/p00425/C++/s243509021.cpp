#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

#define NORTH "North"
#define EAST  "East"
#define WEST  "West"
#define SOUTH "South"
#define RIGHT "Right"
#define LEFT  "Left"
struct DiceState {
  int up;
  int down;
  int north;
  int east;
  int west;
  int south;
  void Reset() {
    up = 1; down = 6; north = 5; east = 3; west = 4; south = 2;
  }
  DiceState() {
    Reset();
  }
};

class Dice {
public:
  Dice();
  ~Dice();
  void Move(int n);
  int GetUpSum() const;
  void ResetState();
private:
  void rotate(int* pa, int* pb, int* pc, int* pd);

  DiceState m_state;
  int m_up_sum;
};

Dice::Dice() : m_up_sum(m_state.up)
{
  ;
}

Dice::~Dice()
{
  ;
}

void Dice::Move(int n)
{
  m_up_sum = m_state.up;

  for (int i = 0; i < n; i++) {
    std::string cmd;
    std::cin >> cmd;
    if (cmd == NORTH) rotate(&m_state.north, &m_state.up, &m_state.south, &m_state.down);
    if (cmd == EAST) rotate(&m_state.east, &m_state.up, &m_state.west, &m_state.down);
    if (cmd == WEST) rotate(&m_state.west, &m_state.up, &m_state.east, &m_state.down);
    if (cmd == SOUTH) rotate(&m_state.south, &m_state.up, &m_state.north, &m_state.down);
    if (cmd == RIGHT) rotate(&m_state.north, &m_state.west, &m_state.south, &m_state.east);
    if (cmd == LEFT) rotate(&m_state.north, &m_state.east, &m_state.south, &m_state.west);

    m_up_sum += m_state.up;
  }
}

int Dice::GetUpSum() const
{
  return m_up_sum;
}

void Dice::ResetState()
{
  m_state.Reset();
}

void Dice::rotate(int* pa, int* pb, int* pc, int* pd)
{
  *pa = *pb;
  *pb = *pc;
  *pc = *pd;
  *pd = 7 - *pb;
}

int main(void)
{
  int n;
  while (true) {
    std::cin >> n;
    if (n == 0) break;
    Dice dc;
    dc.ResetState();
    dc.Move(n);
    std::cout << dc.GetUpSum() << std::endl;
  }

  return 0;
}