#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
#define all(v) v.begin(), v.end()
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int h,w;cin >> h >> w;
    vector<string> table(h+2);
    ll cnt = 0;
    repp(i,1,h+1){
        cin >> table[i];
        table[i] = "." + table[i] + ".";
        //cnt += count(all(table[i]),'#');
        rep(j,w)if(table[i][j+1] == '#')cnt++;
    }
    int dx[] = {0,1};
    int dy[] = {1,0};
    stack<P> st;
    st.push(make_pair(1,1));
    vector<vector<int>> seen(h+2,vector<int>(w+2,0));
    seen[1][1] = true;
    while(!st.empty()){
        auto a = st.top();
        ll x = a.first;
        ll y = a.second;
        st.pop();
        rep(i,2){
            if(table[x + dx[i]][y + dy[i]] == '#' && !seen[x + dx[i]][y + dy[i]]){
                st.push(make_pair(x + dx[i],y + dy[i]));
                seen[x + dx[i]][y + dy[i]] = 1;
            }
        }
    }
    //ll cnt_s = 0;
    //rep(i,h)rep(j,w)if(seen[i+1][j+1])cnt_s++;
    if(!seen[h][w] || cnt != h + w -1 ){
        cout << "Impossible\n";
    }else cout << "Possible\n";
    return 0;
}