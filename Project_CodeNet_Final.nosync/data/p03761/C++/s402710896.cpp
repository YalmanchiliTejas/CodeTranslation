#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<map<char,int>> cm(n);
    rep(i,n) {
        string s;
        cin >> s;
        map<char,int> nm;
        rep(j,s.size()) nm[s[j]]++;
        cm[i] = nm;
    }
    for(char c = 'a'; c <= 'z'; c++) {
        int num = 1001001001;
        rep(j,n) chmin(num,cm[j][c]);
        rep(j,num) cout << c;
    }
    cout << endl;
}