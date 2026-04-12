#include<bits/stdc++.h>
using namespace std;
     
#define lli long long
#define FOR(i,a,b) for (lli i=(a);i<(b);i++)
#define REP(i,n) for (lli i=0;i<(n);i++)
#define rep(i,n) for (lli i=0;i<(n);i++)
     
#define INF LONG_MAX/3
#define PB push_back
#define pb push_back
#define all(a) (a).begin(),(a),end()
#define pll pair<lli,lli>
     
int main(){
  lli H,W,count=0;
  string str[8];

  cin>>H>>W;
  for(int i=0;i<H;i++){
    cin>>str[i];
    for(int j=0;j<W;j++){
      if(str[i][j]=='#')count++;
    }
  }

  if(count==H+W-1)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  
  return 0;
}
