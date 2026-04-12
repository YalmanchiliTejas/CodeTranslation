#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iomanip>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,b;cin >> a >> b;
  vector<string> mine(a);
  rep(i,a){
    cin >> mine[i];
  }
  vector<bool> yoko(a,false);
  vector<bool> tate(b,false);
  for(int i = 0;i<a;i++){
    for(int j = 0;j<b;j++){
      if(mine[i][j]=='#'){
        yoko[i] = true;
        tate[j] = true;
      }
    }
  }
  for (int i = 0; i < a; i++) {
		if (yoko[i]) {
			for (int j = 0; j < b; j++) {
				if (tate[j]) {
					cout << mine[i][j];
				}
			}
			cout << endl;
		}
	}
}