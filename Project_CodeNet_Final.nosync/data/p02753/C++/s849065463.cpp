#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;

int main(){
  string s;
  cin>>s;
  string ans;
  if(s=="AAA"||s=="BBB"){
    ans="No";
  }
  else{
    ans="Yes";
  }
  cout<<ans<<endl;
  return(0);
}
