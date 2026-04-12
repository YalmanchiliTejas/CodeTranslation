#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1000000000000000;
int A[100100];
signed main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++)A[i]=INF;
  int ans=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    int it=upper_bound(A,A+N,-a)-A;
    if(A[it]==INF)ans++;
    A[it]=-a;
  }
  cout<<ans<<endl;
}