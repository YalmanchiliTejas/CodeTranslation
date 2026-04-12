#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  ll k,a,b;
  cin>>k>>a>>b;
  k-=a;
  a-=b;
  if(k<=0){cout<<1<<endl; return 0;}
  if(a<=0)cout<<-1<<endl;
  else{
    cout<<(k+a-1)/a*2+1<<endl;
  }
}