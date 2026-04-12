#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class data{
public:
  int n;
  char c;
};

int main(){
  char c;
  while(cin >> c && c != '#'){
    int ansNS = 0, ansEW = 0;
    vector<data> v[4];
    for(int i=0;i<4;i++){
      for(int j=0;j<13;j++){
	string str;
	cin >> str;
	data d;
	d.c = str[1];
	if('2' <= str[0] && str[0] <= '9') d.n = str[0] - '0';
	else if(str[0] == 'T') d.n = 10;
	else if(str[0] == 'J') d.n = 11;
	else if(str[0] == 'Q') d.n = 12;
	else if(str[0] == 'K') d.n = 13;
	else if(str[0] == 'A') d.n = 14;
	v[i].push_back(d);
      }
    }

    int b = 0;
    for(int i=0;i<13;i++){
      int n = 0, ans = 0;
      bool f = false;
      for(int j=0;j<4;j++){
	if(!f && v[(j+b)%4][i].c == c){
	  ans = (j+b)%4;
	  n = v[(j+b)%4][i].n;
	  f = true;
	}
	else if(!f && v[(j+b)%4][i].n > n && v[b][i].c == v[(j+b)%4][i].c){
	  ans = (j+b)%4;
	  n = v[(j+b)%4][i].n;
	}
	else if(f && v[(j+b)%4][i].c == c && v[(j+b)%4][i].n > n){
	  ans = (j+b)%4;
	  n = v[(j+b)%4][i].n;
	}
      }
      if(ans % 2 == 0) ansNS++;
      else ansEW++;
      b = ans;
    }

    if(ansNS > ansEW) cout << "NS " << ansNS-6 << endl;
    else cout << "EW " << ansEW-6 << endl;

  }
  return 0;
}