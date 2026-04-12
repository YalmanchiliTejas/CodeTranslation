#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--) 
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define downque(que) priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;
typedef long long ll;
typedef vector<vector<int>> Matrix;
const int MOD = 1e9 + 7;
const int MAX = 1e7;
const int INF = numeric_limits<int>::max();

int main(){
string s; cin>>s; 
bool flaga=0,flagb=0;

REP(i,3){
  if(s[i]=='A')flaga=1;
  else flagb=1;
}

    if(flaga==1&&flagb==1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


}