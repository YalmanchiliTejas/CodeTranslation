#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
//template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<58;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

const ll mod=1000000007;

ll mod_pow(ll x,ll y){
    ll res=1;
    while(y>0){
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}

class union_find{
	private:
	vector<int> parent,rank;
	int size;
	public:
    int cnt;

    union_find()=default;
    union_find(int n){ init(n); }

    void init(int n){
		size=n;
		cnt=n;
		parent.resize(size);
		rank.resize(size);
		for(int i=0; i<size; ++i){
			parent[i]=i;
			rank[i]=0;
		}
	}

	int find(int x){
		if(parent[x]==x) return x;
		else return parent[x]=find(parent[x]);
	}

	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]){
			parent[x]=y;
		} else {
			parent[y]=x;
			if(rank[x]==rank[y]) ++rank[x];
		}
        --cnt;
	}

	bool is_same(int x,int y){
		return find(x)==find(y);
	}
};

void solve(){
    while(true){
        ll n,m;
        cin >> n >> m;
        if(n==0 and m==0) break;

        union_find uf(n);
        rep(i,0,m){
            int a,b;
            cin >> a >> b;
            uf.unite(a-1,b-1);
        }
        ll ans=mod_pow(2,uf.cnt);
        if(uf.cnt!=n) ans=(ans+1)%mod;
        cout << ans << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cout << fixed << setprecision(8);
    solve();
    return 0;
}