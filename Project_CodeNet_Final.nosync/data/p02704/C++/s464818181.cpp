#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;

ll ans[503][503];
int n;
ll s[503], t[503], u[503], v[503];

bool ok(){
    for(int i = 0; i < n; i++){
        if(s[i] == 0){
            ll r = -1;
            for(int j = 0; j < n; j++) r &= ans[i][j];
            if(r != u[i]) return false;
        }
        else{
            ll r = 0;
            for(int j = 0; j < n; j++) r |= ans[i][j];
            if(r != u[i]) return false;
        }
    }
    for(int j = 0; j < n; j++){
        if(t[j] == 0){
            ll r = -1;
            for(int i = 0; i < n; i++) r &= ans[i][j];
            if(r != v[j]) return false;
        }
        else{
            ll r = 0;
            for(int i = 0; i < n; i++) r |= ans[i][j];
            if(r != v[j]) return false;
        }
    }
    return true;
}

void show(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    cin >> n;
    vector<int> x, y;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(s[i] == 0) x.push_back(i);
    }
    for(int i = 0; i < n; i++){
        cin >> t[i];
        if(t[i] == 0) y.push_back(i);
    }
    for(int i = 0; i < n; i++) cin >> u[i];
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!(s[i] | t[j])) ans[i][j] = u[i] | v[j];
            if(s[i] & t[j]) ans[i][j] = u[i] & v[j];
        }
    }
    int a = x.size(), b = y.size();
    int p = -1;
    if(a == 1){
        for(int j = 0; j < n; j++){
            if(t[j] == 0){
                continue;
            }
            ll r = 0;
            for(int i = 0; i < n; i++){
                r |= ans[i][j];
            }
            ans[x[0]][j] = (v[j] & (~r)) | u[x[0]];
            p = x[0];
        }
    }
    if(b == 1){
        for(int i = 0; i < n; i++){
            if(s[i] == 0){
                continue;
            }
            ll r = 0;
            for(int j = 0; j < n; j++){
                if(j == y[0]) continue;
                r |= ans[i][j];
            }
            if((r | u[i]) != u[i]){
                cout << -1 << endl;
                return 0;
            }
            ans[i][y[0]] = (u[i] & (~r)) | v[y[0]];
            p = y[0];
        }
    }
    if(a == n - 1){
        for(int j = 0; j < n; j++){
            if(t[j] == 1) continue;
            ll r = -1;
            for(int i = 0; i < n; i++){
                if(s[i] == 0) r &= ans[i][j];
                else p = i;
            }
            ans[p][j] = (u[p] & (~r)) | v[j];
        }
    }
    if(b == n - 1){
        for(int i = 0; i < n; i++){
            if(s[i] == 1) continue;
            ll r = -1;
            for(int j = 0; j < n; j++){
                if(t[j] == 0) r &= ans[i][j];
                else p = j;
            }
            ans[i][p] = (v[p] & (~r)) | u[i];
        }
    }
    else{
        int k1 = 0, k2 = 0;
        for(int i = 0; i < n; i++){
            if(i == p) continue;
            int k;
            if(s[i] == 0){
                k = k1;
                k1 = 1 - k1;
            }
            else{
                k = k2;
                k2 = 1 - k2;
            }
            for(int j = 0; j < n; j++){
                if(s[i] != t[j]){
                    if(k) ans[i][j] = v[j];
                    else ans[i][j] = u[i];
                    k = 1 - k;
                }
            }
        }
    }
    if(ok()){
        show();
    }
    else{
        cout << -1 << endl;
    }
}
