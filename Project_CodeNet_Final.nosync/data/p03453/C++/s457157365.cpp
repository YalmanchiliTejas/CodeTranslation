#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
struct Edge {
	int s;
	int dst;
	long long int cost;
};
using Graph=vector<vector<Edge>>;



const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}

//mod が素数の場合のみ　違う場合はextend euclid を用いる。
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}


vector<long long int> dfs(int start, Graph&g) {
	vector<long long int>depths;

	depths.clear();
	depths.resize(g.size());
	fill(depths.begin(),depths.end(),1ll<<60);
	depths[start]=0;
	priority_queue<pair<long long int,int>>que;
	que.emplace(0,start);
	while (!que.empty()) {
		auto p=que.top();
		que.pop();
		long long int now_cost=-p.first;
		long long int now=p.second;
		if(depths[now]!=now_cost)continue;
		else {
			for (auto e : g[now]) {
				long long next_cost=now_cost+e.cost;
				if (depths[e.dst] > next_cost) {
					depths[e.dst]=next_cost;
					que.push(make_pair(-next_cost,e.dst));
				}
			}
		}
	}
	return depths;
}

vector<Mod>get_nums(int start, const Graph&g, vector<long long int>&depths) {
	vector<Mod>nums(g.size());
	nums[start]=1;
	vector<pair<long long int,int>>vv(g.size());
	for (int i = 0; i < g.size(); ++i) {
		vv[i]=make_pair(depths[i],i);
	}
	sort(vv.begin(),vv.end());
	for (int i = 0; i < vv.size(); ++i) {
		int now=vv[i].second;
		for (auto e : g[now]) {
			if(depths[now]+e.cost==depths[e.dst])nums[e.dst]+=nums[now];
		}
	}
	return nums;
}

int main() {
	int N,M;cin>>N>>M;
	int S,T;cin>>S>>T;
	S--;T--;
	Graph g(N);
	for (int i = 0; i < M; ++i) {
		int a,b,c;cin>>a>>b>>c;
		a--;b--;
		g[a].push_back(Edge{ a,b,c });
		g[b].push_back(Edge{ b,a,c });
	}
	auto from_starts=dfs(S,g);
	auto from_goals=dfs(T,g);
	const long long int total_cost=from_starts[T];

	auto s_nums=get_nums(S,g,from_starts);
	auto t_nums=get_nums(T,g,from_goals);

	vector<int>valids(N);
	for (int i = 0; i < N; ++i) {
		if (from_starts[i] + from_goals[i] == total_cost) {
			valids[i]=true;
		}
	}

	Mod answer=0;
	answer=s_nums[T]*s_nums[T];
	for (int i = 0; i < N; ++i) {
		for (auto e : g[i]) {
			if (valids[i] && valids[e.dst]) {
				if (from_starts[i] + e.cost == from_starts[e.dst]) {
					if (from_starts[i] * 2<total_cost && from_starts[e.dst] * 2>total_cost) {
						answer -= s_nums[i] * s_nums[i] * t_nums[e.dst] * t_nums[e.dst];
					}
				}
			}
			
		}
		if (valids[i]) {
			if (from_starts[i] * 2 == total_cost) {
				answer -= s_nums[i] * t_nums[i] * s_nums[i] * t_nums[i];
			}
		}
		
	}
	cout<<answer.num<<endl;
	return 0;
}

