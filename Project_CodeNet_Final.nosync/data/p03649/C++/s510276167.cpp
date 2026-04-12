#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  int p=0;
  for(int i=0;i<n;i++){
    p+=a[i]/(n+1);
    a[i]=a[i]%(n+1);
  }
  int ans=p;
  if(p>n){
    ans+=(p-n)*n;
    p=n;
  }
  priority_queue<int> que;
  for(int i=0;i<n;i++)que.push(a[i]+p);
  p=0;int t;
  while(que.top()+p>n-1){
    t=que.top();
  // cerr<<t<<' ';
    que.pop();
    que.push(t-(n+1));
    p++;
    ans++;
  }
  cout<<ans;


  
  return 0;
}
