#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MOD = (int)1e9 + 7;
const int INF = 1LL << 60;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    string boin = "aeiou";
    if (boin.find(S)!=string::npos){
        cout << "vowel\n";
    }else{
        cout << "consonant\n";
    }
}