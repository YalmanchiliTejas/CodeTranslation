#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define INF (2 << 28)
#define fr first
#define sc second
using namespace std;

typedef long long ll;
typedef pair<int, int> iP;

int dice[6];

//idx: 0 1 2 3 4 5
//v  : 1 2 3 4 5 6
int rotate(string dir){
  
  int prev[6];
  for(int i = 0; i < 6; i++) prev[i] = dice[i];
  
  if(dir == "North"){
    dice[0] = prev[1];
    dice[1] = prev[5];
    dice[4] = prev[0];
    dice[5] = prev[4];
  }
  else if(dir == "East"){
    dice[0] = prev[3];
    dice[2] = prev[0];
    dice[3] = prev[5];
    dice[5] = prev[2];
  }
  else if(dir == "West"){
    dice[0] = prev[2];
    dice[2] = prev[5];
    dice[3] = prev[0];
    dice[5] = prev[3];
  }
  else if(dir == "South"){
    dice[0] = prev[4];
    dice[1] = prev[0];
    dice[4] = prev[5];
    dice[5] = prev[1];
  }
  else if(dir == "Right"){
    dice[1] = prev[2];
    dice[2] = prev[4];
    dice[3] = prev[1];
    dice[4] = prev[3];
  }
  else if(dir == "Left"){
    dice[1] = prev[3];
    dice[2] = prev[1];
    dice[3] = prev[4];
    dice[4] = prev[2];
  }
  
  return dice[0];
}

int main(){
 
  int n, sum;
  
  while(cin >> n, n){
    sum = 0;
    for(int i = 0; i < 6; i++) dice[i] = i + 1;
    while(n--){
      string s;
      cin >> s;
      sum += rotate(s);
    }
    cout << sum + 1 << endl;
  }

}