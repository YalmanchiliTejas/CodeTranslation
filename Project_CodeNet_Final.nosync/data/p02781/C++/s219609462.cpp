#include <bits/stdc++.h>
#define ll long long
#define MAX 205
using namespace std;

string s;
int n, k, a[MAX];
ll f[MAX][MAX];

ll dp(int x, int lim, int cnt){
    if(x > n) return cnt == k;
    if(f[x][cnt] != -1 && !lim) return f[x][cnt];
    ll res = 0;
    int h = lim?a[x]:9;
    for(int i = 0; i <= h; i++){
        res += dp(x+1, lim&&(i==h), cnt+(i>0));
    }
    if(!lim) f[x][cnt] = res;
    return res;
}

int main()
{
    memset(f, -1, sizeof(f));
    string s;
    cin >> s >> k;
    n = s.length();
    for(int i = 0; i < s.length(); i++){
        a[i+1] = s[i]-'0';
    }
    ll ans = dp(1, 1, 0);
    cout << ans << endl;

    return 0;
}