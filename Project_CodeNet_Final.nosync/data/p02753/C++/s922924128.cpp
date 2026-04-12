#include <bits/stdc++.h>
using intl = long long;
#define rep(i, n) for(intl i = 0; i < (intl)(n); i++)
#define repd(i, n) for(intl i = (intl)((n) - 1); i >= 0; i--)
#define repi(i, a, b) for(intl i = (intl)(a); i < (intl)(b); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define INF = 1e9;
#define debug(x) cout << #x << ":" << x << endl
using namespace std;
void fp(bool flag){
    if(flag)cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main(){
    string s;
    cin >> s;
    fp((s[0] != s[1])||(s[1] != s[2]));
    return 0;
}