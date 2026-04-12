#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    int cnt[26] = {0};
    string s;
    cin >> s;
    rep(j, s.size()){
        cnt[s[j]-'a']++;
    }

    rep(i, n-1){
        string t;
        cin >> t;

        int tmp[26] = {0};
        rep(j, t.size()){
            tmp[t[j]-'a']++;
        }

        rep(j, 26){
            cnt[j] = min(cnt[j], tmp[j]);
        }
    }

    rep(i, 26){
        char c = 'a' + i;
        rep(j, cnt[i]){
            cout << c;
        }
    }
    cout << endl;


    return 0;
}