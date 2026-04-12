//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define elif else if
#define lli long long int
#define ld long double
#define vec vector
#define forn(a) for(lli a=0; a<n; a++)
#define all(x) x.begin(), x.end()
#define deb(x) cerr<<#x<<" = "<<x<<endl

using namespace std;

int main(){
  IOS;

  int n; cin>>n;
  string s; cin>>s;
  int k; cin>>k; k--;

  forn(i){
    if(s[i]!=s[k]) cout<<'*';
    else cout<<s[i];
  }cout<<endl;

  return 0;
}