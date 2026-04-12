#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const long long N = 1e3 + 17;
ll a[N], b[N], cnt, ans, lnt, n, m, r1, r0, l1, l0, sum, mx, h, c[N], t[N], mn = N, x, y, k;
pair<ll,ll>pr[N];
vector<ll>v,v2;
map<ll,ll>mp;
bool used[N];
char ch[1005];
ll prime[N] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for(ll i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    mx = a[0];
    for(ll i = 0; i < n; i ++)
    {
        if(a[i] >= mx)
        {
            cnt ++;
            mx = a[i];
        }
    }
    cout << cnt;
}
