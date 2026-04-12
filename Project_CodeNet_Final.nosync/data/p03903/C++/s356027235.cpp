#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF      1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

struct UF{
	int par[4000];
	int rank[4000];
	int si[4000];

	void init(int n){
		rep(i,n){
			par[i] = i;
			rank[i] = 0;
			si[i] = 1;
		}
	}

	int find(int x){
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]){
			par[x] = y;
			si[y] += si[x];
		} else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
			si[x] += si[y];
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
} uf;
int n, m, k;
bool saw[4000];
ll sum = 0;
vector<PP> e;
vector<P> ee[4000];
ll par[30][4000];
ll cnt[30][4000];
ll dep[4000];

ll lca(int s, int t){
    ll ret = 0;
    if(dep[s] > dep[t]){
        ll dif = dep[s]-dep[t];
        for(int i = 0;;i++){
            if(dif == 0) break;
            if(dif&1){
                ret = max(ret,cnt[i][s]);
                s = par[i][s];
            }
            dif /= 2;
        }
    }
    if(dep[s] < dep[t]){
        ll dif = dep[t]-dep[s];
        for(int i = 0;;i++){
            if(dif==0)break;
            if(dif&1){
                ret = max(ret,cnt[i][t]);
                t = par[i][t];
            }
            dif /= 2;
        }
    }
    //cout << s << " " << t<< " " << ret << endl;
    if(s == t){
        return ret;
    }
    for(int i = 29; i >= 0; i--){
        if(par[i][s] == par[i][t]) continue;
        ret = max(ret,cnt[i][t]);
        ret = max(ret,cnt[i][s]);
        s = par[i][s];
        t = par[i][t];
    }
    ret = max(ret,cnt[0][t]);
    ret = max(ret,cnt[0][s]);
    return ret;
}

void dfs(int v){
    saw[v] = true;
    rep(i,ee[v].size()){
        if(saw[ee[v][i].first]) continue;
        dep[ee[v][i].first] = dep[v]+1;
        dfs(ee[v][i].first);
        par[0][ee[v][i].first] = v;
        cnt[0][ee[v][i].first] = ee[v][i].second;
    }
}

int main(){
    cin >> n >> m;
    uf.init(n);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        e.push_back(PP(c,P(a,b)));
    }
    sort(e.begin(),e.end());
    rep(i,e.size()){
        if(!uf.same(e[i].second.first,e[i].second.second)){
            uf.unite(e[i].second.first,e[i].second.second);
            ee[e[i].second.first].push_back(P(e[i].second.second,e[i].first));
            ee[e[i].second.second].push_back(P(e[i].second.first,e[i].first));
            //cout << e[i].second.second << " " << e[i].second.first << endl;
            sum += e[i].first;
        }
    }
    //cout << sum << endl;
    dfs(0);
    //rep(i,n) cout << dep[i] << " ";
    //cout << endl;
    for(int j = 1; j < 30; j++){
        rep(i,n){
            par[j][i] = par[j-1][par[j-1][i]];
            cnt[j][i] = max(cnt[j-1][i],cnt[j-1][par[j-1][i]]);
        }
    }
    cin >> k;
    rep(i,k){
        int s, t;
        cin >> s >> t;
        s--; t--;
        cout << sum - lca(s,t) << endl;
    }
}
