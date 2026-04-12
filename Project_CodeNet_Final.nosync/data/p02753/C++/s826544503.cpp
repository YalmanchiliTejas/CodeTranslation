#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (int i = 0; i < n; i++)
#define IREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(a, b) for (int i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int main(){
    string s;
    cin >> s;
    if(s[0]==s[1]&&s[0]==s[2]){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}