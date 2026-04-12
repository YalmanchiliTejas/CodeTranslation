#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define map map<string,int>
#define repa(p,A) for(auto p:A)
#define pb push_back
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())

using namespace std;
int main() {
  ll N,B,A,C;
  ll count=0;
  cin>>N;
  C=0;
  rep(i,0,N) {
    cin>>B;
    C=max(C,B);
    
    if(C==B) {
      count+=1;
    }
  }

  cout<<count<<endl;
  
    
}
