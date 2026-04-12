#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int > pp;
typedef long long ll;
 
#define sz(x) (int)x.size() 
int const N=1e6+10,oo=1e9;
ll const OO=2e18;
double const eps=1e-8,PI=acos(-1);
int mod=oo+7;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  string s;
  cin>>n>>s>>k;
  for(int i=0;i<n;i++){
      if(s[i]==s[k-1])cout<<s[i];
      else cout<<'*';
  }
  return 0;
}