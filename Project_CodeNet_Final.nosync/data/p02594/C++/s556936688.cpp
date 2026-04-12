/*

*/
#include<bits/stdc++.h>

using namespace std;
using ll=long long;
#define rep2(i, a, n) for(int i = (a); i < (n); i++)
#define rep(i, n) rep2(i,0,n)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}
void flagfunc3(bool flag){cout<<(flag?"Yes\n":"No\n");}

int main(){
  cin.tie(nullptr);ios_base::sync_with_stdio(false);
  int x;cin>>x;
  flagfunc3(x>=30);
}