#include <bits/stdc++.h>

#define FILE
#define fr first
#define se second

using namespace std;

const long long N = 2e5 + 7;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;

int n;
int k;
int res;
string s;
string t;
int main()
{
    #ifdef FILEs
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    cin >> s >> k;
    n = (int)s.size();
    t = string(n, '0');
    if(k == 1){
        for(int i = 0; i < n; i ++){
            for(int ni = 1; ni <= 9; ni ++){
                t[i] = (ni + '0');
                res += (t <= s);
                t[i] = '0';
            }
        }
    }
    else if(k == 2){
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                for(int ni = 1; ni <= 9; ni ++){
                    for(int nj = 1; nj <= 9; nj ++){
                        t[i] = (ni + '0');
                        t[j] = (nj + '0');
                        res += (t <= s);
                        t[i] = t[j] = '0';
                    }
                }
            }
        }
    }
    else if(k == 3){
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                for(int k = j + 1; k < n; k ++){
                    for(int ni = 1; ni <= 9; ni ++){
                        for(int nj = 1; nj <= 9; nj ++){
                            for(int nk = 1; nk <= 9; nk ++){
                                t[i] = (ni + '0');
                                t[j] = (nj + '0');
                                t[k] = (nk + '0');
                                res += (t <= s);
                                t[i] = t[j] = t[k] = '0';
                            }
                        }
                    }
                }
            }
        }
    }
    cout << res << "\n";
}
