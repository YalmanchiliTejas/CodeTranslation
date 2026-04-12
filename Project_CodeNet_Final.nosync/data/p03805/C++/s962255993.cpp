#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>


#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long
//#define lint long long

const int INF = 1e9;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;

//typedef pair<int, int> P;

int n,m;
int miti[10][10];
int ans;

signed main(){
  cin >> n>> m;
  REP(i,m){
    int a1,b1;
    cin >> a1 >> b1;
    miti[a1][b1] = 1;
    miti[b1][a1] = 1;
  }
  vector<int> v;
  REP(i,n){
    v.pb(i+1);
  }
  do {
    int f = 1;
    if(v[0]!=1) f=0;
    REP(j,v.size()-1){
      if(miti[v[j]][v[j+1]]==0) f=0;
    }
    if (f==1) ans ++;
  } while(next_permutation(v.begin(), v.end()));
  cout << ans << endl;
  return 0;
}
