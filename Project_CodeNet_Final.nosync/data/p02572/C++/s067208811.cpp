#include <iostream>
#include <fstream>
#include <numeric>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <cstring>
#include <sstream>
#include <complex>

#define f first
#define s second
#define ll long long
#define ld double
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define y0 eto
#define y1 mezhdy
#define y2 nami
#define left extermination
#define right dismemberment
 
using namespace std;
 
double start_moment = 0;
double get_runtime() { return 1.0*clock()/CLOCKS_PER_SEC; }
void reset_timer() { start_moment = get_runtime(); }
double timer_time() { return get_runtime() - start_moment; }
void runtime(){cout<<fixed<<setprecision(5)<<get_runtime()<<'\n';}
 
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
 
template <class T>void read(vector<T> &a,ll n){T x; a.clear();for(ll i=0;i<n;i++){cin>>x;a.pb(x);}}
template <class T>void write(vector<T> &a){for(T x : a) cout<<x<<' ';cout<<'\n';}

const ll mod=1000000007;
int n;
ll res,sum;

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("INPUT.txt","r",stdin);
//    freopen("OUTPUT.txt", "w", stdout);
    
    cin>>n;
    cin>>sum;
    for(int i=1;i<n;i++)
    {
        ll cur;
        cin>>cur;
        res=(res+cur*sum)%mod;
        sum=(sum+cur)%mod;
    }
    cout<<res;
    
}
