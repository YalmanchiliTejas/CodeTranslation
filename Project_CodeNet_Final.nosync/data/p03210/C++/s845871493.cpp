#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const long long N = 3e6 + 17;
ll a[N], b[N], cnt = 1, ans, lnt, n, m, r1, r0, l1, l0, sum, mx, h, c[N], t[N], mn = N, x, y, k;
pair<ll,ll>pr[N];
vector<ll>v,v2;
map<ll,ll>mp;
bool used[N];
char ch[N];
ll prime[N] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    if(x == 3 or x == 5 or x == 7)
    {
        cout <<"YES";
        return 0;
    }
    cout << "NO";
}