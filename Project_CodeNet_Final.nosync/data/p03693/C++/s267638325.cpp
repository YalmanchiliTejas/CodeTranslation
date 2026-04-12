#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<functional>
using namespace std;

#define INF 1<<21
#define DIV 1000000007

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  if ((b + 10*g) % 4 == 0) {
	cout << "YES" << endl;
  }
  else {
	cout << "NO" << endl;
  }

}