#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
int m;
string s;
const int mod = 1e9 + 7;

const int maxn = 2e5 + 5;
int f[maxn];
int pre[maxn];

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

void single(){
    f[0] = 1;
    f[1] = 2;
    for(int i = 2;i <= n;i++){
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    int ans = (2 * f[n - 1] - f[n - 2]) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
}

void solve(int v){
    v /= 2, n /= 2; 
    v = min(v, n);
    f[0] = 1;
    pre[0] = 1;
    for(int i = 1;i <= v;i++){
        f[i] = pre[i - 1];
        pre[i] = pre[i - 1];
        add(pre[i], f[i]);
    }
    for(int i = v + 1;i <= n;i++){
        f[i] = (pre[i - 1] - pre[i - v - 1] + mod) % mod;
        pre[i] = pre[i - 1];
        add(pre[i], f[i]);
    }
    int ans = 0;
    for(int i = 1;i <= v;i++){
        int r = n - i;
        int l = n - v;
        int tmp;
        if(l == 0){
            tmp = pre[r];
        }else{
            tmp = (pre[r] - pre[l - 1] + mod) % mod;
        }
        add(ans, tmp);
    }
    ans = ans * 2 % mod;
    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> s; 
    if(s[0] == 'B'){
        for(int i = 0;i < m;i++){
            if(s[i] == 'R')
                s[i] = 'B';
            else
                s[i] = 'R';
        }
    } 
    int first = -1, last = -1;
    for(int i = 0;i < m;i++){
        if(s[i] == 'B'){
            if(first == -1)
                first = i;
            last = max(last, i);
        }
    }
    if(first == -1){
        single();
    }else{
        if(n & 1){
            cout << 0 << endl;
        }else{
            string s1 = s.substr(0, last + 1);
            int len = s1.length();
            if(first == 1){
                cout << 2 << endl;
            }else{
                int val = first / 2 * 2 + 2;
                int pre = first;
                for(int i = first + 1;i < len;i++){
                    if(s[i] == 'B'){
                        int x = i - pre;
                        pre = i;
                        if(x % 2 == 0){
                            val = min(val, x);
                        }
                    } 
                }
                solve(val);
            }
        }
    }    
    return 0;
}
