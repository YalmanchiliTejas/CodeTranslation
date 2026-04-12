#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> g(h);
  REP(i, h){
  	cin >> g[i];
  }
  vector<bool> R(h, false);
  vector<bool> C(w, false);
  REP(i, h){
  	REP(j, w){
  		if (g[i][j] == '#'){
  			R[i] = true;
  			C[j] = true;
  		}
  	}
  }
  REP(i, h){
  	REP(j, w){
  		if (R[i] == true && C[j] == true){
  			cout << g[i][j];
  		}
  	}
  	if (R[i] == true){cout << "\n";}
  }
  
}
