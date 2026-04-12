#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char Trump;
string card[4][13];// N, W, S, W
int point[2];
int num[256];

void make() {
  for(int i = 2; i <= 9; ++i)
    num['0'+i] = i;
  num['T'] = 10;
  num['J'] = 11;
  num['Q'] = 12;
  num['K'] = 13;
  num['A'] = 14;
}

int main() {
  make();
  while(cin >> Trump && Trump != '#') {
    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 13; ++j) {
	cin >> card[i][j];
      }
    }
    fill(point, point+2, 0);
    int d = 0;
    for(int i = 0; i < 13; ++i) {
      pair<pair<int, int>,int> w = make_pair(make_pair(-1,0),0);
      for(int j = 0; j < 4; ++j) {
	pair<pair<int, int>,int> p;
	string &c = card[(d+j)%4][i];
	int a;
	if(c[1] == Trump)              a = 2;
	else if(c[1] == card[d][i][1]) a = 1;
	else                           a = 0;
	p = make_pair(make_pair(a, num[c[0]]), -j);
	w = max(w, p);
      }
      d = (d-w.second)%4;
      ++point[d%2];
    }
    if(point[0] > point[1])
      cout << "NS " << point[0]-6 << endl;
    else
      cout << "EW " << point[1]-6 << endl;
  }
  return 0;
}