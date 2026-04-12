#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    string s;
    cin >> s;
    int N = s.size();

    for (int i=0; i<N-1; i++){
        string sb;
        sb = s.substr(i,2);
        if (sb == "AC"){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
