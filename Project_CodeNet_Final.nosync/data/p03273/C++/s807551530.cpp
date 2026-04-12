#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
typedef long long ll;
using namespace std;
int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char > > a;
  vector<char > tmp(W, ' ');
  bool onlydot = true;
  REP(i, H){
    onlydot = true;
    REP(j, W){
      cin >> tmp[j];
      if(tmp[j] != '.'){
	onlydot = false;
      }
    }
    if(!onlydot){
      a.push_back(tmp);
    }
  }
  
  // cout << "end a" << endl;
  // REP(i, a.size()){
  //   REP(j, W){
  //     cout << a[i][j] ;
  //   }
  //   cout << endl;
  // }
  // cout << "end a" << endl;

  vector<vector<char > > b;
  vector<char > tmp2(a.size(), ' ');
  REP(j, W){
    onlydot = true;
    REP(i, a.size()){
      tmp2[i] = a[i][j];
      if(a[i][j] != '.'){
	onlydot = false;
      }
    }
    if(!onlydot){
      b.push_back(tmp2);
    }
  }

  REP(i, a.size()){
    REP(j, b.size()){
      cout << b[j][i];
    }
    cout << endl;
  }
}
