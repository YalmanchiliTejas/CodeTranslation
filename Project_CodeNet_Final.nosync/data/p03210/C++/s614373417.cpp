#include<cstdio>
#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

int main(int argc, char* argv[]){
  int s;
  cin >> s;
  if(s == 7 || s == 5 || s == 3){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO";
  return 0;
}