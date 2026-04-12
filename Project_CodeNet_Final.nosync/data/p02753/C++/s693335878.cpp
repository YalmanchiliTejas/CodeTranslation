 
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const double pi = acos(-1.0);
int main(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin >> S;
    if(S[0] == S[1] and S[1] == S[2]) cout << "No";
    else cout << "Yes";
    return 0;   
}
    