#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    string s;cin>>s;
    map<char, int> mc;
    for(char c : s){
        mc[c]++;
    }
    for(int i=0; i<n-1;i++){
        map<char, int> mt;
        string t;cin>>t;
        for(auto a:t) mt[a]++;
        for(auto a : mc){
            if(a.second==0) continue;
            mc[a.first] = min(a.second, mt[a.first]);
        }
    }
    vector<char> ans;
    for(auto a : mc) {
        rep(i, a.second) ans.push_back(a.first);
    }
    sort(all(ans));
    rep(i, ans.size()) cout<<ans[i];
    cout<<endl;
    return 0;

}