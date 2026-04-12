#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    if (a+b<=2*c)
    {
        cout << a*x+b*y << endl;
    }
    else
    {
        if (x>=y)
        {
            if (a>2*c)
            {
                cout << y*(2*c) + (x-y) * (2*c) << endl;
            }
            else
            {
                cout << y*2*c + (x-y) * a << endl;
            }
        }
        else
        {
            if (b>2*c)
            {
                cout << y*2*c << endl;
            }
            else
            {
                cout << x*2*c + (y-x) * b << endl;
            }
            
        }
        
    }
}
