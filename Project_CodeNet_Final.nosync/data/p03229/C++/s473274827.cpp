#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  sort(A.begin(),A.end());
  int ans1=0;
  for(int i=0;i<N/2-1;i++)
    ans1-=A[i]*2;
  for(int i=N/2-1;i<(N+1)/2;i++)
    ans1-=A[i];
  for(int i=(N+1)/2;i<N/2+1;i++)
    ans1+=A[i];
  for(int i=N/2+1;i<N;i++)
    ans1+=A[i]*2;
  int ans2=0;
  for(int i=0;i<(N+1)/2-1;i++)
    ans2-=A[i]*2;
  for(int i=(N+1)/2-1;i<N/2;i++)
    ans2-=A[i];
  for(int i=N/2;i<(N+1)/2+1;i++)
    ans2+=A[i];
  for(int i=(N+1)/2+1;i<N;i++)
    ans2+=A[i]*2;
  cout<<max(ans1,ans2)<<endl;
}