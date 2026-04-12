#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
#define reps(i,f,n) for(int i=(f); i<=(n); ++i)
#define outl(x) cout << x << '\n';

#define INF (1 << 29)

#define FAST cin.tie(0), ios::sync_with_stdio(false)
inline int chmax(int &a, int b){return b>a ? a=b,1 : 0;}
inline int chmin(int &a, int b){return b<a ? a=b,1 : 0;}
//________

main(){
 int x,y,z;
 cin >> x >> y >> z;
 x -= z, y+=z;
 outl(x/y);
}
