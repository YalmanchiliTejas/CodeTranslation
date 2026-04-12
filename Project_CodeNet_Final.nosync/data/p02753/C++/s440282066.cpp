#include <bits/stdc++.h>
#define db(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define MOD 1000000007
using namespace std;
const long long INF = 3*1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    int countA = 0, countB = 0;
    for(int i = 0; i < S.size(); i++)
        if(S[i] == 'A') countA++;
        else countB++;
    if(countA == 3 || countB == 3) cout << "No\n";
    else cout << "Yes\n";
}