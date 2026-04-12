#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
string s;
bool ans[100010];

bool is_ok(bool is_sheep1,bool is_sheep2) {
    ans[0]=is_sheep1;
    ans[1]=is_sheep2;
    for (int i=1;i<=n;i++) {
        bool flag=((s[i%n]=='o') ^ ans[i]);
        if (flag) ans[i+1]=!ans[i-1];
        else ans[i+1]=ans[i-1];
    }
    if (ans[0]==ans[n] && ans[1]==ans[n+1]) return 1;
    else return 0;
}

int main() { 
    cin >> n;
    cin >> s;
    bool is_sheep1[4] = {true,true,false,false};
    bool is_sheep2[4] = {true,false,true,false};
    for (int i=0;i<4;i++) {
        bool flag=is_ok(is_sheep1[i],is_sheep2[i]);
        if (flag) {
            for (int j=0;j<n;j++) {
                if (ans[j]) cout << 'S';
                else cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}