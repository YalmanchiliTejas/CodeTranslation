#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define downque(que)  priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;
typedef long long ll;
const int MOD = 1e9+7;


int main(){
 int h,w; cin>>h>>w;
 char masu[h][w];
 bool hb[h]; REP(i,h)hb[i]=false;
 bool wb[w]; REP(i,w)wb[i]=false;
 REP(i,h)REP(j,w)cin>>masu[i][j];

 REP(i,h){
     bool check=true;
     REP(j,w){
         if(masu[i][j]=='#')check=false;
     }
     if(check)hb[i]=true;//trueならその行は白行
 }
 REP(j,w){
     bool check=true;
     REP(i,h){
         if(masu[i][j]=='#')check=false;
     }
  if(check)wb[j]=true;
 }

 REP(i,h){
     REP(j,w){
         if(hb[i]!=true&&wb[j]!=true)cout<<masu[i][j];
     }
     if(hb[i]!=true)cout<<endl;
 }
 
}
