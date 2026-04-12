#include<bits/stdc++.h>
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;

int main(){
    string S;
    cin >> S;
    int n = S.size();
    bool flag1 = false;
    bool flag2 = false;
    rep(i, n) {
        if (S[i] == 'A') {
            flag1 = true;
        } else if (S[i] == 'B') {
            flag2 = true;
        }
    }
    if (flag1 && flag2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}