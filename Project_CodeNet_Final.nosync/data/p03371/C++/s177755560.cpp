#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define pb push_back
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())

using namespace std;
int main() {
  ll A,B,C,X,Y,Z;
  cin>>X>>Y>>Z>>A>>B;
  int count=min(X+Y,2*Z)*min(A,B);
  if(A>=B)
  count+=(A-B)*min(X,2*Z);
  if(B>=A)
  count+=(B-A)*min(Y,2*Z);
  cout<<count<<endl;
}
  
  
  
