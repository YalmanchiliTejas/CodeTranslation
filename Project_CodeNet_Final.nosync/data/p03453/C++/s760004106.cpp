#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int MC = 100010;
const LL mod = 1e9 + 7;
const LL INF = 20123456789012345;
int N,M,S,T;
LL z[MC];
vector<P2> V[MC];
priority_queue<P2 , vector<P2> , greater<P2> > Q;
LL ans_s[MC] , ans_t[MC];
int r[MC];

int main(){
	cin >> N >> M;
	cin >> S >> T;
	repp(i,0,M){
		int x,y;
		LL d;
		cin >> x >> y >> d;
		d *= 2;
		V[x].PB(MP(d,y));
		V[y].PB(MP(d,x));
	}
	fill(z,z+MC,INF);
	z[S] = 0;
	Q.push(MP(0,S));
	while(!Q.empty()){
		int x = Q.top().second; Q.pop();
		for(auto u : V[x]){
			if(z[u.second] > z[x] + u.first){
				z[u.second] = z[x] + u.first;
				Q.push(MP(z[u.second],u.second));
			}
		}
	}
	LL c = z[T] / 2;
	ans_s[S] = 1;
	ans_t[T] = 1;
	repp(i,0,N) r[i] = i+1;
	sort(r,r+N,[&](const int &x , const int &y){return z[x] < z[y];});
	repp(i,0,N){
		for(auto u : V[r[i]]){
			if(z[u.second] == z[r[i]] + u.first){
				(ans_s[u.second] += ans_s[r[i]]) %= mod;
			}
		}
	}
	repm(i,N-1,-1){
		for(auto u : V[r[i]]){
			if(z[u.second] + u.first == z[r[i]]){
				(ans_t[u.second] += ans_t[r[i]]) %= mod;
			}
		}
	}
	LL ans0 = 0 , ans1 = 0;
	repp(i,1,N+1){
		if(z[i] == c){
			LL w = ans_s[i] * ans_t[i] % mod;
			(ans0 += w) %= mod;
			(ans1 += w * w) %= mod;
		} else if(z[i] < c){
			for(auto u : V[i]) if(z[u.second] == z[i] + u.first && z[u.second] > c){
				LL w = ans_s[i] * ans_t[u.second] % mod;
				(ans0 += w) %= mod;
				(ans1 += w * w) %= mod;
			}
		}
	}
	cout << (ans0 * ans0 % mod - ans1 + mod) % mod << endl;
	return 0;
}
