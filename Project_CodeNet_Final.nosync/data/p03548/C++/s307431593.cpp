//
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MOD 1000000007
#define PI 3.14159265
#define EPS 1e-9
#define Pi acos(-1.0)
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define clean(arr,val) memset(arr,val,sizeof(arr))
#define forn(i,n) forr(i,0,n)
#define PB push_back
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pll> vpll;

/*CODE START HERE*/

int x, y, z, temp;
int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin >> x >> y >> z;
    forr(i,1,x){
        temp = (i*y)+2*z+(i-1)*z;
        if(temp <= x){
            ans = i;
        }else{
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}