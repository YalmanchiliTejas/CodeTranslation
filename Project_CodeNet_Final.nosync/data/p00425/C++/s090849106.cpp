#include <iostream>
#include <string>

using namespace std;

int surface[6];

void manip_north() {
  int t = surface[0];
  int s1 = surface[1];
  int s2 = surface[2];
  int s3 = surface[3];
  int s4 = surface[4];
  int b = surface[5];

  surface[0] = s3;
  surface[1] = t;
  surface[2] = s2;
  surface[3] = b;
  surface[4] = s4;
  surface[5] = s1;
}

void manip_east() {
  int t = surface[0];
  int s1 = surface[1];
  int s2 = surface[2];
  int s3 = surface[3];
  int s4 = surface[4];
  int b = surface[5];

  surface[0] = s2;
  surface[1] = s1;
  surface[2] = b;
  surface[3] = s3;
  surface[4] = t;
  surface[5] = s4;
}

void manip_west() {
  int t = surface[0];
  int s1 = surface[1];
  int s2 = surface[2];
  int s3 = surface[3];
  int s4 = surface[4];
  int b = surface[5];

  surface[0] = s4;
  surface[1] = s1;
  surface[2] = t;
  surface[3] = s3;
  surface[4] = b;
  surface[5] = s2;
}

void manip_south() {
  int t = surface[0];
  int s1 = surface[1];
  int s2 = surface[2];
  int s3 = surface[3];
  int s4 = surface[4];
  int b = surface[5];

  surface[0] = s1;
  surface[1] = b;
  surface[2] = s2;
  surface[3] = t;
  surface[4] = s4;
  surface[5] = s3;
}

void manip_right() {
  int t = surface[0];
  int s1 = surface[1];
  int s2 = surface[2];
  int s3 = surface[3];
  int s4 = surface[4];
  int b = surface[5];

  surface[0] = t;
  surface[1] = s2;
  surface[2] = s3;
  surface[3] = s4;
  surface[4] = s1;
  surface[5] = b;
}

void manip_left() {
  int t = surface[0];
  int s1 = surface[1];
  int s2 = surface[2];
  int s3 = surface[3];
  int s4 = surface[4];
  int b = surface[5];

  surface[0] = t;
  surface[1] = s4;
  surface[2] = s1;
  surface[3] = s2;
  surface[4] = s3;
  surface[5] = b;
}

int main() {
  while (true) {
    int n;
    surface[0] = 1;
    surface[1] = 5;
    surface[2] = 4;
    surface[3] = 2;
    surface[4] = 3;
    surface[5] = 6;
    int score = 1;
    
    cin >> n;

    if (n == 0) break;

    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;

      if (s == "North") {
        manip_north();
      } else if (s == "East") {
        manip_east();
      } else if (s == "South") {
        manip_south();
      } else if (s == "West") {
        manip_west();
      } else if (s == "Right") {
        manip_right();
      } else if (s == "Left") {
        manip_left();
      } else {
      }

      score += surface[0];
    }

    cout << score << endl;
  }

  return 0;
}

