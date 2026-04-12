#include<bits/stdc++.h>
using namespace std;

int N,t[100000];
int main(){
  cin>>N;
  for(int i=0;i<N;i++) cin>>t[i];
  sort(t,t+N);
  set<int> st;
  for(int i=1;i<=t[N-1];i++)if(t[N-1]%i==0)st.insert(i);
  int ans=0;
  for(int i=0;i<N;i++)ans+=*st.lower_bound(t[i])-t[i];
  cout<<ans<<endl;
  return 0;
}

