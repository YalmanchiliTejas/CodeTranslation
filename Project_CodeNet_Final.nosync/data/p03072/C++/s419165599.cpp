#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, h, cur, ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (h >= cur) {
            ans++;
            cur = h;
        }
    }
    cout << ans << "\n";
    //system("pause");
    return 0;
}