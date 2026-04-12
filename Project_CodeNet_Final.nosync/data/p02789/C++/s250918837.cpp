#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(container) container.begin(),container.end()
#define fast ios::sync_with_stdio(0); cin.tie(0)
#define int long long
const int mod = 1e9+7;  
int power(int a,int b) { if(b==0) return 1; int res = power(a,b/2); if(b&1) return res * res * a; else return res * res; }


int32_t main(){
    
  fast;
  int n,m; cin >> n >> m;
  if(n==m) cout << "Yes";
  else cout << "No";

  

  return 0;
}