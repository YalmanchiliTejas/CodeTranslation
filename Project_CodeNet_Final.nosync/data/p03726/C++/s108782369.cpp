#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 0x3fffffff;


int main(){
	//ios_base::sync_with_stdio(0);
	int N;
	set<int> v[100005];
	bool ans = false;

	cin >> N;
	rep(i,N-1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].insert(b);
		v[b].insert(a);
	}

	queue<int> que;
	rep(i,N) if( v[i].size() == 1 ) que.push(i);

	while( !que.empty() ){
		int n = que.front();
		que.pop();
		if( v[n].empty() ){
			ans = true;
			break;
		}
		int p = *(v[n].begin());
		for(auto t: v[p]){
			v[t].erase(p);
			if( v[t].size() == 1 ) que.push(t);
		}
	}

	cout << (ans ? "First" : "Second") << endl;

	return 0;
}
