#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif

typedef pair<int,int> pii;
const int inf=1e9;
const long long int infll=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

void solve(){
    int n,m,w,t;
    cin >> n >> m >> w >> t;
    map<string,int> mp;
    vector<int> v(m),p(m),l(n),x(n),y(n);
    vector<vector<string>> r(n);
    vector<vector<int>> q(n);
    rep(i,0,m){
        string s;
        cin >> s >> v[i] >> p[i];
        mp[s]=i;
    }
    rep(i,0,n){
        cin >> l[i] >> x[i] >> y[i];
        r[i].resize(l[i]);
        q[i].resize(l[i]);
        rep(j,0,l[i]) cin >> r[i][j] >> q[i][j];
    }

    vector<int> dist((1<<n)-1);
    vector<vector<int>> vis((1<<n)-1);
    rep(i,1,1<<n){
        bitset<7> bs(i);
        vector<int> perm,min_perm;
        rep(j,0,n) if(bs[j]) perm.push_back(j);
        dist[i-1]=inf;
        do{
            int d=0,prev_x=0,prev_y=0;
            for(int pos:perm){
                d+=abs(x[pos]-prev_x)+abs(y[pos]-prev_y);
                prev_x=x[pos];
                prev_y=y[pos];
            }
            d+=abs(prev_x)+abs(prev_y);
            if(dist[i-1]>d){
                dist[i-1]=d;
                min_perm=perm;
            }
            vis[i-1]=min_perm;
        }while(next_permutation(perm.begin(),perm.end()));
    }

    vector<int64_t> dp1((1<<n)-1);
    rep(k,0,(1<<n)-1){
        vector<int> dp(w+1);
        for(int pos:vis[k]){
            rep(i,0,l[pos]){
                int idx=mp[r[pos][i]];
                int weight=v[idx],diff=p[idx]-q[pos][i];
                if(diff<=0) continue;
                rep(j,0,w+1){
                    if(j-weight<0) continue;
                    dp[j]=max(dp[j],dp[j-weight]+diff);
                }
            }
        }
        dp1[k]=dp[w];
    }

    vector<int64_t> dp2(t+1);
    rep(i,0,t+1){
        rep(j,0,(1<<n)-1){
            int i_=i+dist[j];
            if(i_>t) continue;
            dp2[i_]=max(dp2[i_],dp2[i]+dp1[j]);
        }
    }
    cout << dp2[t] << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}