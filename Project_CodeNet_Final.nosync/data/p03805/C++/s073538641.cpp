#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<int> a(m),b(m);
    rep(i,m) cin >> a[i] >> b[i];

    map<P,int> G;
    rep(i,m){
      P p1,p2;
      p1.first = a[i]; p1.second = b[i];
      p2.first = b[i]; p2.second = a[i];
      G[p1] = 1; G[p2] = 1;
    }
  
    int array[n];
    rep(i,n) array[i] = i+1;
    
    int ans = 0;
    do{
      bool ok = true;
      if(array[0] != 1) continue;
      rep(i,n-1){
        P p;
        p.first = array[i];
        p.second = array[i+1];
        if( !G[p] ) ok = false;
      }
      if(ok) ans++;
    }while(next_permutation(array, array + n));

    cout << ans << endl;       
    
    return 0;
}
