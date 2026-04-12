#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rfor(i, a, b) for(int i = a; i < (int)b; i++)
#define all(ary) (ary).begin(), (ary).end()
#define debug(x) cerr << #x << ": " << x << '\n'
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
using namespace std;
using v = vector<int>;
using ll = long long;
template <class T = int> T in(){ T x; cin >> x; return (x);}

int main(int argc, char *argv[]){
    char s; cin >> s;
    string res = "vowel";
    if(s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o') res = "vowel";
    else res = "consonant";
    cout << res << endl;
    return 0;
}