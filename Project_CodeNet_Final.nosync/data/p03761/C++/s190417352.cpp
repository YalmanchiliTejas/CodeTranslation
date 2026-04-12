#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    map<int,int>mp1;
    rep(i,n) {
        if(i==0) {
            string s;
            cin >> s;
            rep(j,s.size()) {
                mp1[s[j]-'0']++;
            }
            continue;
        }
        string s;
        cin >> s;
        map<int,int>mp2;
        rep(j,s.size()) {
            mp2[s[j]-'0']++;
        }
        for(int j = 49;j<=74;j++) {
            if(mp1[j]>0) {
                if(mp1[j]>=mp2[j]) {
                    mp1[j] = mp2[j];
                }
            }
        }
    }
    vector<int>use;
    for(int i = 49;i<=74;i++) {
        int num = mp1[i];
        rep(j,num) use.push_back(i);
    }
    sort(use.begin(),use.end());
    string ans = "";
    rep(i,use.size()) {
        ans += use[i]+'0';
    }
    cout << ans << endl;
}