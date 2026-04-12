//url:
//problem name: Brick Break

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    cin >> N;
    map<char,int> mp;
    vector<string> res;
    REP(i,N) {
        string S;
        cin >> S;
        res.push_back(S);
    }
    for(char c:res[0]) {
        if(mp.count(c)) mp[c]++;
        else mp[c] = 1;
    }
    for(int i = 1; i < N; i++) {
        map<char,int> mp2;
        for(char c:res[i]) {
            if(mp2.count(c)) mp2[c]++;
            else mp2[c] = 1;
        }
        for(auto x:mp2) {
            if(mp.count(x.first)) chmin(mp[x.first],mp2[x.first]);
            else mp.erase(x.first);
        }

        for(auto x:mp) {
            if(mp2.count(x.first)) chmin(mp2[x.first],mp[x.first]);
            else mp.erase(x.first);
        }
    }
    for(auto c: mp) {
        REP(i,c.second) cout << c.first;
    }
    cout << endl;
}