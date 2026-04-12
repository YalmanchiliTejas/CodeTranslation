#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const long long mod = 1e9 + 7;

using namespace std;

int k;
int d[N];
int f[N];

int add(int x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
        return x;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s;
        cin >> s >> k;
        for(int i = 0; i < s.size(); i++){
                s[i] -= '0';
        }
        for(int i = 0; i < s[0]; i++){
                d[i % k] = add(d[i % k], 1);
        }
        int eq = s[0] % k;
        for(int i = 1; i < s.size(); i++){
                for(int j = 0; j < k; j++){
                        for(int h = 0; h < 10; h++){
                                int nj = (j + h) % k;
                                f[nj] = add(f[nj], d[j]);
                        }
                }
                for(int h = 0; h < s[i]; h++){
                        int nj = (eq + h) % k;
                        f[nj] = add(f[nj], 1);
                }
                for(int j = 0; j < k; j++){
                        d[j] = f[j];
                        f[j] = 0;
                }
                eq = (eq + s[i]) % k;
        }
        int res = (eq == 0);
        res = add(res, d[0]);
        res -= 1;
        if(res < 0){
                res += mod;
        }
        cout << res << "\n";
}

