#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define ll long long
int main(){
  int N;
  cin>>N;
  int H[N+1];
  rep(i,N) cin>>H[i];
  int x=0,ans=0;
  rep(i,N){
    if(H[i]>=x){
      ans++;
      x=H[i];
    }
  }
  cout<<ans<<endl;
}