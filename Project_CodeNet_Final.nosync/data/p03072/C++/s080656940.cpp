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
  vec<int> v(n); 
  forn(i) cin>>v[i];
  
  int cont = 0;
  int max = v[0];
  forn(i){
    if(v[i] >= max){
      cont++;
      max = v[i];
    }
  }
  
  cout<<cont<<endl;

  return 0;
}