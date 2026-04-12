#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fl first
#define fr second
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;

const int N = 100 + 5;

char s[N];
int n, k;
LL f[N][5][2];

LL DP(int now, int cnt, int ok)
{
    if (now == n + 1) return cnt == k;
    if (cnt > k) return 0;
    if (f[now][cnt][ok]) return f[now][cnt][ok];
    LL res = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (ok && i > s[now] - '0') break;
        res += DP(now + 1, cnt + (i != 0), ok && (i == s[now] - '0'));
    }
    //cout << now << " " << cnt << " " << ok << " " << res << endl;
    return f[now][cnt][ok] = res;
}

int main()
{
    scanf("%s%d", s + 1, &k);
    n = strlen(s + 1);
    printf("%lld\n", DP(1, 0, 1));
    return 0;
}