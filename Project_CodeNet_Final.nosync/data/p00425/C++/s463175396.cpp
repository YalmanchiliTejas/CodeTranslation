#include <iostream>
#include <string>

enum direction {
  TOP, EAST, WEST, SOUTH, NORTH, BOTTOM
};

void north(int *state);
void east(int *state);
void west(int *state);
void south(int *state);
void right(int *state);
void left(int *state);

int main(int argc, char const* argv[])
{
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0) {
      break;
    }
    // top, east, west, south, north, bottom
    int state[] = { 1, 3, 4, 2, 5, 6 };
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      std::string s;
      std::cin >> s;
      if ("North" == s) {
        north(state);
      } else if ("East" == s) {
        east(state);
      } else if ("West" == s) {
        west(state);
      } else if ("South" == s) {
        south(state);
      } else if ("Right" == s) {
        right(state);
      } else if ("Left" == s) {
        left(state);
      } else {
        return 1;
      }
      ans += state[0];
    }
    std::cout << ans << std::endl;
  }
  return 0;
}

void north(int *state) {
  state[NORTH] = state[TOP];
  state[TOP] = state[SOUTH];
  state[SOUTH] = 7 - state[NORTH];
  state[BOTTOM] = 7 - state[TOP];
}

void east(int *state) {
  state[EAST] = state[TOP];
  state[TOP] = state[WEST];
  state[WEST] = 7 - state[EAST];
  state[BOTTOM] = 7 - state[TOP];
}

void west(int *state) {
  state[WEST] = state[TOP];
  state[TOP] = state[EAST];
  state[EAST] = 7 - state[WEST];
  state[BOTTOM] = 7 - state[TOP];
}

void south(int *state) {
  state[SOUTH] = state[TOP];
  state[TOP] = state[NORTH];
  state[NORTH] = 7 - state[SOUTH];
  state[BOTTOM] = 7 - state[TOP];
}

void right(int *state) {
  state[WEST] = state[SOUTH];
  state[SOUTH] = state[EAST];
  state[EAST] = 7 - state[WEST];
  state[NORTH] = 7 - state[SOUTH];
}

void left(int *state) {
  state[EAST] = state[SOUTH];
  state[SOUTH] = state[WEST];
  state[WEST] = 7 - state[EAST];
  state[NORTH] = 7 - state[SOUTH];
}