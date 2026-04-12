#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int n;
bool s[500], t[500], u[500], v[500];
int a[500][500];
ull ans[500][500];
void end(){
    cout << -1 << endl;
    exit(0);
}
void solve(){
    memset(a, 0xff, sizeof(a));
    vector<int> x(n), y(n);
    auto px = x.begin(), py = y.begin();
    for(int i = 0; i < n; i++) x[i] = y[i] = i;
    for(int i = 0; i < n; i++){
        if(s[i] ^ u[i]){
            for(int j = 0; j < n; j++) a[i][j] = u[i];
            px = x.erase(px);
        }
        else px++;
    }
    for(int j = 0; j < n; j++){
        if(t[j] ^ v[j]){
            for(int i = 0; i < n; i++){
                if(a[i][j] == (v[j] ^ 1)) end();
                a[i][j] = v[j];
            }
            py = y.erase(py);
        }
        else py++;
    }
    if(x.size() > 1 && y.size() > 1){
        bool b = 0;
        for(int i : x){
            bool c = b;
            for(int j : y){
                a[i][j] = c;
                c = !c;
            }
            b = !b;
        }
        return;
    }
    if(x.size() == 1){
        const int i = x[0];
        bool flag = 0;
        for(int j : y){
            a[i][j] = u[i];
            bool flag2 = 1;
            for(int i = 0; i < n; i++) if(a[i][j] == v[j]){
                flag2 = 0;
                break;
            }
            if(flag2) a[i][j] = v[j];
            else flag = 1;
        }
        if(flag) return;
    }
    if(y.size() == 1){
        const int j = y[0];
        bool flag = 0;
        for(int i : x){
            a[i][j] = v[j];
            bool flag2 = 1;
            for(int j = 0; j < n; j++) if(a[i][j] == u[i]){
                flag2 = 0;
                break;
            }
            if(flag2) a[i][j] = u[i];
            else flag = 1;
        }
        if(flag) return;
    }
    for(int i : x){
        bool flag = 1;
        for(int j = 0; j < n; j++) if(a[i][j] == u[i]){
            flag = 0;
            break;
        }
        if(flag) end();
    }
    for(int j : y){
        bool flag = 1;
        for(int i = 0; i < n; i++) if(a[i][j] == v[j]){
            flag = 0;
            break;
        }
        if(flag) end();
    }
}
int main(){
    cin >> n;
    vector<ull> u_(n), v_(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    for(auto& i : u_) cin >> i;
    for(auto& i : v_) cin >> i;
    for(int bit = 64; bit--; ){
        for(int i = 0; i < n; i++) u[i] = u_[i] >> bit & 1;
        for(int i = 0; i < n; i++) v[i] = v_[i] >> bit & 1;
        solve();
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            ans[i][j] <<= 1;
            ans[i][j] |= a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
}

