#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int llint;
typedef pair<ll, ll> pa;
#define MM 1000000000
#define MOD MM+7
#define MAX 101000
#define MAP 110
#define initial_value -1
#define Pair pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int a,b,c,x,y;
int main(){
    cin >> a >> b >> c >> x >> y;
    ll ans = a*x + b*y;
    ll tmp;
    if(x > y){
        tmp = c*2*y + (x-y)*a;
        ans = min(tmp,ans);
    } else {
        tmp = c*2*x + (y-x)*b;
        ans = min(ans,tmp);
    }
    tmp = max(x,y)*c*2;
    ans = min(ans,tmp);
    cout << ans << endl;
}

