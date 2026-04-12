#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main(){
    int n;
    cin >> n;
    int cnt[26];
    rep(i, 26) cnt[i] = 1e8;
    rep(i, n) {
        string tmp_s;
        cin >> tmp_s;
        vector<int> tmp_cnt(26, 0);
        rep(i, tmp_s.length()) {
            ++tmp_cnt[tmp_s[i] - 'a'];
        }
        rep(i, 26) {
            cnt[i] = min(cnt[i], tmp_cnt[i]);
        }
    }
    vector<char> ans;
    rep(i, 26) {
        int tmp_cnt = cnt[i];
        rep(j, tmp_cnt) ans.push_back(char(i+'a'));
    }
    if ( ans.size() == 0 ) {
        cout << " " << endl;
    }
    else {
        sort(ans.begin(), ans.end());
        for ( auto tmp_ans : ans ) {
            cout << tmp_ans;
        }
        cout << endl;
    }
    return 0;
}