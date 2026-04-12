#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int A=0,B=0;
    rep(i, 3){
        if(s[i]=='A') A++;
        else B++;
    }
    if(A>0&&B>0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}