#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 105;
int n, m, r[N], c[N];
char arr[N][N];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;++i)
    {
        for(int j = 0;j < m;++j)
        {
            cin >> arr[i][j];
            if(arr[i][j] == '.')
                ++r[i], ++c[j];
        }
    }
    for(int i = 0;i < n;++i)
    {
        if(r[i] != m)
        {
            for(int j = 0;j < m;++j)
                if(c[j] != n)
                    cout << arr[i][j];
            cout << '\n';
        }
    }
    return 0;
}
