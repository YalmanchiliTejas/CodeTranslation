#include<iostream>
#include<cstdio>
using namespace std;

int main(){

  int n, ans, cnt, valid;
  int team[101][2] = {0};

  while(scanf("%d, %d", &n, &ans) != EOF){
    if(n == 0 && ans == 0) break;
    team[n][0] = ans;
  }

  cnt = 1;
  for(int i=30; i>=0; i--){
    valid = 0;
    for(int j=1; j<101; j++){
      if(team[j][0] == i){
        valid = 1;
        team[j][1] = cnt;
      }
    }
    if(valid == 1) cnt++;
  }

  while(cin >> n){
    cout << team[n][1] << endl;
  }

  return 0;

}