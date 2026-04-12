#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
typedef pair<int,int> P;
#define mod 1000000007


int main(){
   int n;
   cin >> n;
   int ans=0;
   int mi=-inf;
   rep(i,n){
       int h;
       cin >> h;
       if(h>=mi) ans++;
       mi=max(mi,h);
   }
   cout << ans << endl;
    return 0;
}
