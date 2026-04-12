#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define taskname "A"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
const ll inf = 1e18;

int f[maxn];
int n , a , b , c , d;
int fac[maxn] , rfac[maxn];
int Pow(int x , int y){
    if(y == 0)return 1;
    ll r = Pow(x , y / 2);
    if(y & 1)return r * r % mod * x % mod;
    return r * r % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP" , "r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    cin >> n >> a >> b >> c >> d;
    fac[0] = 1;
    for(int i = 1 ; i <= n ; ++i){
        fac[i] = (ll)fac[i - 1] * i % mod;
        rfac[i] = Pow(fac[i] , mod - 2);
    }
    f[0] = 1;
    for(int i = a ; i <= b ; ++i){
        for(int t = n - 1 ; t >= 0 ; --t){
            for(int j = c ; t + j * i <= n && j <= d ; ++j){
                f[t + i * j] += (ll)f[t] * Pow(rfac[i],j) % mod * rfac[j] % mod;
                if(f[t + i * j] >= mod)f[t + i * j] -= mod;
            }
        }
    }
    cout << (ll)f[n] * fac[n] % mod;
}

