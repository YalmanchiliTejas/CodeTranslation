#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  ll k,a,b;
  cin>>k>>a>>b;
  if(k<=a){
  	cout<<1<<endl;
    return 0;
  }
  
  if(a<=b){
  	cout<<-1<<endl;
    return 0;
  }
  cout<<(k-b-1)/(a-b)*2+1<<endl;  
  return 0;
}
