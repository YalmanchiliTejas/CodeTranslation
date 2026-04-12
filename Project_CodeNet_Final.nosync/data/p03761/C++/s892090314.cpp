#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin >> n;
    map<int,int> m;
    rep(i,26){
        m[i] = INF;
    }
    rep(i,n){
        string s;
        cin >> s;
        map<int,int> h;
        rep(j,s.size()){
            h[s[j]-'a']++;
        }
        rep(j,26){
            if(m[j]>h[j]){
                m[j] = h[j];
            }
        }
    }
    string ans = "";
    rep(i,26){
        rep(j,m[i]){
            ans += 'a' + i;
        }
    }
    cout << ans << endl;
}