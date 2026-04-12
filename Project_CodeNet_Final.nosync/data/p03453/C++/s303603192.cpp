#include<bits/stdc++.h>
/*
*/

using namespace std;


int main(){
	long long int mod = 1000000007LL;
	long long int N, M;
	cin >> N >> M;
	long long int S, T;
	cin >> S >> T;
	S--; T--;
	vector<vector<pair<long long int, long long int>>>route(N);
	vector<long long int>u(M), v(M), d(M);
	for( size_t i = 0; i < M; i++ ){
		long long int U, V, D;
		cin >> U >> V >> D;
		U--; V--;
		u[i] = U;
		v[i] = V;
		d[i] = D;
		route[U].push_back(make_pair(V, D));
		route[V].push_back(make_pair(U, D));
	}
	priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>>que;
	que.push(make_pair(0, S));
	long long int STtime = 1LL << 60;
	vector < long long int >Stime(N, 1LL << 60), Ttime(N, 1LL << 60), Scount(N, 0), Tcount(N, 0);
	Stime[S] = 0;
	Ttime[T] = 0;
	Scount[S] = 1;
	Tcount[T] = 1;
	while( que.size() ){
		auto now = que.top(); que.pop();
		if( now.first > STtime ){
			break;
		}
		if( Stime[now.second] < now.first ){
			continue;
		}
		if( now.second == T ){
			STtime = now.first;
			continue;
		}
		for( auto x : route[now.second] ){
			auto next = now;
			next.first += x.second;
			next.second = x.first;
			if( Stime[next.second] == next.first ){
				Scount[next.second] += Scount[now.second];
				Scount[next.second] %= mod;
				continue;
			}
			if( Stime[next.second] > next.first ){
				Stime[next.second] = next.first;
				Scount[next.second] = Scount[now.second];
				que.push(next);
			}
		}
	}
	que.push(make_pair(0, T));
	while( que.size() ){
		auto now = que.top(); que.pop();
		if( now.first > STtime ){
			break;
		}
		if( Ttime[now.second] < now.first ){
			continue;
		}
		if( now.second == S ){
			STtime = now.first;
			continue;
		}
		for( auto x : route[now.second] ){
			auto next = now;
			next.first += x.second;
			next.second = x.first;
			if( Ttime[next.second] == next.first ){
				Tcount[next.second] += Tcount[now.second];
				Tcount[next.second] %= mod;
				continue;
			}
			if( Ttime[next.second] > next.first ){
				Ttime[next.second] = next.first;
				Tcount[next.second] = Tcount[now.second];
				que.push(next);
			}
		}
	}
	vector<long long int >test;
	for( size_t i = 0; i < N; i++ ){
		if( Stime[i] * 2 == STtime && Ttime[i] * 2 == STtime ){
			test.push_back(Scount[i] * Tcount[i] % mod);
		}
	}
	for( size_t i = 0; i < M; i++ ){
		if( Stime[u[i]] + Ttime[v[i]] + d[i] == STtime ){
			if( Stime[u[i]] * 2 < STtime && ( Stime[u[i]] + d[i] ) * 2 > STtime ){
				test.push_back(Scount[u[i]] * Tcount[v[i]] % mod);
			}
		}
		if( Stime[v[i]] + Ttime[u[i]] + d[i] == STtime ){
			if( Stime[v[i]] * 2 < STtime && ( Stime[v[i]] + d[i] ) * 2 > STtime ){
				test.push_back(Scount[v[i]] * Tcount[u[i]] % mod);
			}
		}
	}
	long long int ans = 0,memo=0;
	for( auto x : test ){
		ans += x * memo;
		memo += x;
		memo %= mod;
		ans %= mod;
	}
	ans *= 2;
	ans %= mod;
	cout << ans << endl;
}