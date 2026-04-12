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
  int n,k;
  string s;
  cin>>n>>s>>k;
  for(int i=0;i<n;i++){
    if(s[i]==s[k-1])cout<<s[i];
    else cout<<"*";
  }
  cout<<endl;
  return 0;
}
