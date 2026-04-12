#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cnt(26,50);
    rep(i,n) {
        string s;
        cin >> s;
        int m=s.size();
        vector<int> c(26);
        rep(j,m) ++c[s[j]-'a'];
        rep(j,26) cnt[j]=min(cnt[j],c[j]);
    }
    rep(i,26) {
        char c=i+'a';
        rep(j,cnt[i]) {
            cout << c;
        }
    }
    cout << endl;
    return 0;   
}