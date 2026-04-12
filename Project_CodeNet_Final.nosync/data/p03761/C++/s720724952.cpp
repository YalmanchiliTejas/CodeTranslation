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
 int n; cin>>n;
 string s[n]; REP(i,n)cin>>s[i];
 int alp[26];

 REP(i,n){
   int alp2[26]; REP(j,26)alp2[j]=0;
   REP(j,s[i].size()){
     REP(k,26)if(s[i][j]=='a'+k)alp2[k]++;
     }
   if(i==0)REP(k,26)alp[k]=alp2[k];
   else REP(k,26)if(alp[k]>=alp2[k])alp[k]=alp2[k];
   //REP(k,26)cout<<alp2[k]<<' ';
   //cout<<endl;
   }
  //REP(k,26)cout<<alp[k]<<' ';
  string res="";
 REP(i,26){
   REP(j,alp[i])res+='a'+i;
 }
  cout<<res<<endl;
}
