#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i<(b); ++i)
#define rep(i, n) for (int i=0; i<(n); ++i)
#define out(x) cout << x << endl

int main(){
    string S;
    cin >> S;
    if (S[0] == S[1] && S[1] == S[2]) out("No");
    else out("Yes");
}