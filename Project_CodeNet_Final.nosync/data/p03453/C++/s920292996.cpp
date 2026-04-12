#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
//const ull mod = 1e9 + 7;
const ll mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

// debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

// conversion number to bit
string num2bit(ll num, ll len){
  string bit = "";
  REP(i, len){
    bit += char('0'+(num>>i & 1));
  }
  return bit;
}

struct tsui{
	ll U, V, D;
};

struct Edge{
    ll dst;
    ll weight;
    Edge(ll dst, ll weight): dst(dst), weight(weight) {}
};

struct TmpDist{
    ll vertex;
    ll dist;
    TmpDist(ll vertex, ll dist): vertex(vertex), dist(dist) {}
    bool operator< (const TmpDist& right)const{
        return dist > right.dist;
    }
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
const ll INFLL = LLONG_MAX/3;

vector<ll> dijkstra(Graph &G, ll r){
    ll V = G.size();
    vector<ll> dist(V, INFLL);
    priority_queue<TmpDist> pq;
    vector<bool> check(V, false);
    TmpDist init(r, 0);
    pq.push(init);
    while(!pq.empty()){
        TmpDist td = pq.top();pq.pop();
        ll now = td.vertex;
        if(!check[now]){
            check[now] = true;
            dist[now] = td.dist;
            for (int i=0;i<(int)G[now].size();i++){
                if(dist[G[now][i].dst] > td.dist + G[now][i].weight){
                    TmpDist tdCandidate(G[now][i].dst, td.dist + G[now][i].weight);
                    pq.push(tdCandidate);
                }
            }
        }
    }
    return dist;
}

vector<ll> count_spath(Graph &G, ll r, vector<ll> const &dist){
	ll V = G.size();
	vector<ll> cnt(V, 0);
	cnt[r] = 1;
	vector<pll> D(V);
	REP(i, V){
		D[i].first = dist[i];
		D[i].second = i;
	}
	sort(D.begin(), D.end());
	REP(i, V){
		ll now = D[i].second;
		for(auto e: G[now]){
			if(e.weight + dist[now] == dist[e.dst]){
				cnt[e.dst] += cnt[now];
				cnt[e.dst] %= mod;
			}
		}
	}
	return cnt;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, S, T;
    cin >> N >> M >> S >> T;
    S--, T--;

    Graph G(N);
    vector<tsui> E(M);

    REP(i, M){
    	ll U, V, D;
    	cin >> U >> V >> D;
    	U--, V--;
    	Edge e(V, D);
    	Edge f(U, D);
    	G[U].push_back(e);
    	G[V].push_back(f);
    	E[i].U = U;
    	E[i].V = V;
    	E[i].D = D;
    }

    auto distS = dijkstra(G, S);
    auto distT = dijkstra(G, T);

    auto combS = count_spath(G, S, distS);
    auto combT = count_spath(G, T, distT);

    /*
    dump(distS)
    dump(combS)
    dump(distT)
    dump(combT)
    //*/

    ll D = distS[T];

    ll res = combS[T] * combT[S] % mod;

	REP(i, N){
		if(2*distS[i] == D){
			ll tmp = combS[i];
			tmp %= mod;
			tmp *= combS[i];
			tmp %= mod;
			tmp *= combT[i];
			tmp %= mod;
			tmp *= combT[i];
			tmp %= mod;

			res -= tmp;
			res += mod;
			res %= mod;
		}
	}

    REP(i, M){
    	ll du = distS[E[i].U];
    	ll dv = distT[E[i].V];
    	ll cu = combS[E[i].U];
    	ll cv = combT[E[i].V];

    	if(du + dv + E[i].D == D){
    		if(2*du<D && 2*dv<D){
    			//dump(E[i].U)
    			//dump(E[i].V)

    			ll tmp = cu;
    			tmp %= mod;
    			tmp *= cu;
    			tmp %= mod;
    			tmp *= cv;
    			tmp %= mod;
    			tmp *= cv;
    			tmp %= mod;

    			res -= tmp;
    			res += mod;
    			res %= mod;
    		}
    	}

    	du = distT[E[i].U];
    	dv = distS[E[i].V];
    	cu = combT[E[i].U];
    	cv = combS[E[i].V];

    	if(du + dv + E[i].D == D){
    		if(2*du<D && 2*dv<D){
    			//dump(E[i].U)
    			//dump(E[i].V)
    			ll tmp = cu;
    			tmp %= mod;
    			tmp *= cu;
    			tmp %= mod;
    			tmp *= cv;
    			tmp %= mod;
    			tmp *= cv;
    			tmp %= mod;

    			res -= tmp;
    			res += mod;
    			res %= mod;
    		}
    	}
    }

    cout << res << endl;

    return 0;
}