#include <bits/stdc++.h>
using namespace std;

int A[100]={0};
int l,n,r;

int solve();

int main(){
  int i,j,k,ans=0;
  while(1){
    cin >> n >> l >> r;
    if(n+l+r==0)break;
    ans = 0;
    for(i=0;i<n;i++)cin >> A[i];
    ans = solve();
    cout << ans << endl;
  }
  return 0;
}

int solve(){
  int i,j,now,countn=0;
  for(i=l;i<=r;i++){
    now = i;
    for(j=0;j<n;j++){
      if(j%2==0&&now%A[j]==0){
	countn++;
	break;
      }
      else if(j%2==1&&now%A[j]==0)break;
      if(j==n-1){
	if(n%2==0)countn++;
      }
    }
  }
  return countn;
}

