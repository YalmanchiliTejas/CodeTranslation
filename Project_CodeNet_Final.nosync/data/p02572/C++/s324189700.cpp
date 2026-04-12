#include<bits/stdc++.h>

#define bitGet(a, i) a & (1 << i)
#define bitOn(a, i) a != (1 << i)
#define bitOff(a, i) a &= ~(1 << i)
#define bitMake(a, i) a = (1 << N)
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define ull unsigned long long
#define ll long long
#define ld long double
#define pri(a) cout << a << " "
#define pril(a) cout << a << " "
#define pb push_back
#define mp make_pair
#define vi vector<int> 
#define pi pair<int, int>
#define oo INT_MAX
#define sz(a) (int)(a.size()-1)
#define maxN 200005

using namespace std;

int n;
ll a[maxN], sum[maxN], rs;

const int mod = 1000000007;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif // !ONLINE_JUDGE

    cin >> n;

    fto(i, 1, n) {cin >> a[i]; sum[i] = (sum[i-1] + a[i]) % mod;}

    fto(i, 2, n) rs = (rs + (sum[i-1] * a[i]) % mod) % mod;

    cout << rs;
    
    return 0;
}
