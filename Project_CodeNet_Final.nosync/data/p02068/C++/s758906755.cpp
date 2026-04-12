#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;
#define F first
#define S second

signed main(){
  int n,MAX=0;
  cin>>n;
  int a[n];
  r(i,n){
    cin>>a[i];
    if(a[i]>1)MAX=max(a[i],MAX);
  }
  unordered_set<int>st;
  r(i,n)r(j,n){
    st.insert(__gcd(a[i],a[j]));
  }
  for(auto &e:st){
    if(e==1)continue;
    int sum=0;
    r(i,n){
      if(a[i]%e==0)sum+=a[i];
    }
    MAX=max(sum,MAX);
  }
  cout<<MAX<<endl;
}
