#include <bits/stdc++.h>
          
#define pb push_back
#define ll long long
#define f first
#define s second
#define ld long double
#define fa fflush(stdout); 
#define mp make_pair
using namespace std;
void data() {
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);;                                                      
} 
int dx[5] = {-1, 0, 0, 1};
int dy[5] = {0, -1, 1, 0};
  
const int N = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll big = 1e9;
  
int main() 
{
    data();     
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i];
    }
    ll ans = 0;
    ll s = 0;
    for (int i = 1; i <= n; i++)
    {
    	ans += a[i] * s;
    	s += a[i];
    	ans %= mod;
    	s %= mod;
    }
    cout << ans;
}
//a[3] * (a[1] + a[2]