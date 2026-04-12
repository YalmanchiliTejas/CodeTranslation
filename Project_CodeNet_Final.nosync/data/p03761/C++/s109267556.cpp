#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>
 
#define lint long long
#define REP(i, x, n) for(int i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }
    vector< vector<int> > cnt(n);
    rep(i, n){
        cnt[i].resize(26);
        rep(j, s[i].size()){
            cnt[i][s[i][j]-'a']++;
        }
    }
    vector<int> ans(26, IINF);
    rep(i, 26){
        rep(j, n){
            ans[i] = min(ans[i], cnt[j][i]);
        }
    }
    rep(i, 26){
        char c = i + 'a';
        rep(j, ans[i]){
            cout << c;
        }
    }
    cout << endl;
    return 0;
}