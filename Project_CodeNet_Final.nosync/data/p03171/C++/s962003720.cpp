#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define pb push_back
#define fastIO ios::sync_with_stdio(0); cin.tie(0);

vi arr;
int n;

ll cache[3005][3005][2];

//Taro - 0, Jiro - 1
ll dpSol(int l, int r, bool turn)
{
    if(l == r)
    {
        if(turn)
            return -arr[l];
        return arr[l];
    }
    
    ll &res = cache[l][r][turn];
    if(res != -1)
        return res;
    
    if(turn)
    {
        ll ans1 = -arr[l] + dpSol(l + 1, r, !turn);
        ll ans2 = -arr[r] + dpSol(l, r - 1, !turn);
        return res = min(ans1, ans2);
    }
    
    ll ans1 = arr[l] + dpSol(l + 1, r, !turn);
    ll ans2 = arr[r] + dpSol(l, r - 1, !turn);
    return res = max(ans1, ans2);
}

int main()
{
    fastIO
    cin >> n;
    
    arr = vi(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
        
    memset(cache, -1, sizeof(cache));
        
    cout << dpSol(0, n - 1, 0);

    return 0;
}