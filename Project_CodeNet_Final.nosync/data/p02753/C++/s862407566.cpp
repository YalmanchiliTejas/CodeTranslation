#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
 
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    string s; cin >> s;
    if(s[0] == s[1] && s[1] == s[2]) {
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}
