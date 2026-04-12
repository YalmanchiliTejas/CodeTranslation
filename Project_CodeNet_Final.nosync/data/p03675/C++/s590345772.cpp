#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back
#define pf push_front
#define fr(i,n) for(int i=0;i<n;i++)

int main(){
  ll n,a;
  deque<ll> dq;
  cin>>n;
  fr(i,n){
    cin>>a;
    if(i%2) dq.pf(a);
    else dq.pb(a);
  }
  if(n%2) for(auto it=dq.end();(it--)!=dq.begin();) cout<<*it<<" ";
  else for(auto it=dq.begin();it!=dq.end();it++) cout<<*it<<" ";
  cout<<endl;
}