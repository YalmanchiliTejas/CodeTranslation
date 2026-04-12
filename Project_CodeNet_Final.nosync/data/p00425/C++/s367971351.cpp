#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Dice[] = {1,2,3,4,5,6};
void initialize_dice() {
  for(int i=1;i<=6;i++) {
    Dice[i-1] = i;
  }
}
void operation_dice(int op[]) {
  int Dice_tmp[6];
  for(int i=0;i<6;i++) {
    Dice_tmp[i] = Dice[i];
  }
  for(int i=0;i<6;i++) {
    Dice[i] = Dice_tmp[op[i]];
  }
}
void print_dice() {
  cout << "print_dice : {";
  for(int i=0;i<6;i++) {
    cout << Dice[i] << (i+1==6 ? "}" : ",");
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // initialize operation array
  // Next Dice[i] = Dice[op[i]]
  int north[] = {1,5,2,3,0,4};
  int east[] = {3,1,0,5,4,2};
  int west[]= {2,1,5,0,4,3};
  int sorth[] = {4,0,2,3,5,1};
  int right[] = {0,2,4,1,3,5};
  int left[] = {0,3,1,4,2,5};

  int n;
  int score;
  while(true) {
    cin >> n;
    if(n == 0) break;

    initialize_dice();
    score = Dice[0];
    char str[6];
    for(int i=0;i<n;i++) {
      cin >> str;
      switch(str[0]) {
        case 'N':
          // cout << "North" << endl;
          operation_dice(north);
          break;
        case 'E':
          // cout << "East" << endl;
          operation_dice(east);
          break;
        case 'W':
          // cout << "West" << endl;
          operation_dice(west);
          break;
        case 'S':
          // cout << "South" << endl;
          operation_dice(sorth);
          break;
        case 'R':
          // cout << "Right" << endl;
          operation_dice(right);
          break;
        case 'L':
          // cout << "Left" << endl;
          operation_dice(left);
          break;
      } // end switch
      score += Dice[0];
      //print_dice();
    } // end for
    cout << score << endl;
  } // end while
}