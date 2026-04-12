#include <iostream>
using namespace std;

int Dice[6];
void init() {
  for(int i=1;i<=6;i++)
    Dice[i-1] = i;
}
void lotate(int op[]) {
  int Dice_tmp[6];
  for(int i=0;i<6;i++)
    Dice_tmp[i] = Dice[i];
  for(int i=0;i<6;i++)
    Dice[i] = Dice_tmp[op[i]];
}
int main() {
  int north[] = {1,5,2,3,0,4};
  int east[] = {3,1,0,5,4,2};
  int west[]= {2,1,5,0,4,3};
  int sorth[] = {4,0,2,3,5,1};
  int right[] = {0,2,4,1,3,5};
  int left[] = {0,3,1,4,2,5};

  int n,score;
  char s[6];
  while(true) {
    cin >> n;
    if(n == 0) break;
    init();
    score = Dice[0];
    for(int i=0;i<n;i++) {
      cin >> s;
      if(s[0] == 'N') lotate(north);
      if(s[0] == 'E') lotate(east);
      if(s[0] == 'W') lotate(west);
      if(s[0] == 'S') lotate(sorth);
      if(s[0] == 'R') lotate(right);
      if(s[0] == 'L') lotate(left);
      score += Dice[0];
    }
    cout << score << endl;
  }
}