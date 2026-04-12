#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int little = min(x,y);
    ll ans = 0;
    if(a+b < 2*c){
        ans += (a+b) * little;
    }
    else{
        ans += (2*c) * little;
    }
    ll res = max(x,y) - little;
    if(x < y){
        ans += min(b,2*c) * res;
    }
    else{
     ans += min(a,2*c) * res;   
    }
    cout << ans << endl;
}