#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll a, b, c, x, y; cin>>a>>b>>c>>x>>y;
    if(a+b<=2*c){
        cout << a*x + b*y << endl;
    }
    else{
        ll MIN=min(x, y);
        ll ans=MIN*c*2LL;
        x-=MIN, y-=MIN;
        ll sum=0;
        if(x>0){
            sum=min(x*a, x*2*c);
        }
        else{
            sum=min(y*b, y*2*c);
            //cout << sum << endl;
        }
        cout << ans + sum << endl;
    }
}