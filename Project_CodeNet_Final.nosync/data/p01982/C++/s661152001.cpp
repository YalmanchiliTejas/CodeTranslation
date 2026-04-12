#include <bits/stdc++.h>
using namespace std;
int n,l,r,ans=0,A[55]={};

void solve(int x){
  for(int i=1;i<=n;i++){
    if(x%A[i]==0){
      if(i%2==0);
      else ans++;
      return;
    }
  }
  if(n%2==0) ans++;
  else;
  return;
}

int main(){
  while(1){
    cin >> n >> l >> r;
    ans=0;
    if(n==0 && l==0 && r==0) break;
    for(int i=1;i<=n;i++) cin >> A[i];
    for(int x=l;x<=r;x++) solve(x);
    cout << ans << endl;
  }
  return 0;
}

