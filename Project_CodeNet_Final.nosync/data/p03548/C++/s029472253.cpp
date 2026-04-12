#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
  int X,Y,Z;
  cin>>X>>Y>>Z;
  int ans=0;
    if(Y+Z*2<=X){
        X-=Y+Z*2;
        ans++;
        ans+=X/(Y+Z);
    }
  cout<<ans<<endl;
}
