#include<bits/stdc++.h>
/*
*/

using namespace std;


template<typename T>
class UF {
public:
	UF() {
		size = 0;
	}

	//値を挿入する
	void push( T a ) {
		M[a] = size;
		V.push_back( size );
		rank.push_back( 0 );
		C.push_back( 1 );
		size++;
	}

	//同じグループにする
	void unite( T a, T b ) {
		long long int x = find( M[a] );
		long long int y = find( M[b] );
		if( x == y )return;
		if( rank[x] < rank[y] ) {
			V[x] = y;
			C[y] += C[x];
		} else {
			V[y] = x;
			C[x] += C[y];
			if( rank[x] == rank[y] )rank[x]++;
		}
	}

	void merge( T a, T b ) {
		unite( a, b );
	}

	//同じグループにいるかどうか判定する
	bool same( T a, T b ) {
		return find( M[a] ) == find( M[b] );
	}

	//今何グループあるか数を返す
	long long int group() {
		set<long long int>S;
		for( long long int i = 0; i < V.size(); i++ ) {
			S.insert( find( V[i] ) );
		}
		return S.size();
	}

	//グループに属している数を返す
	long long int count( T a ) {
		return C[find( M[a] )];
	}

	//今属しているグループのIDを返す
	long long int groupID( T a ) {
		return find( M[a] );
	}

	//同じグループのメンバーを返す
	vector<T>friendList( T a ) {
		long long int inputID = find( M[a] );
		vector<T>ret;
		for( auto now : M ) {
			if( find( now.second ) == inputID ) {
				ret.emplace_back( now.first );
			}
		}
		return ret;
	}

private:
	vector<long long int>C, V, rank;
	map < T, long long int>M;
	long long int size;

	//祖先までたどる
	long long int find( long long int x ) {
		if( V[x] == x )return x;
		else return V[x] = find( V[x] );
	}
};



int main() {
	long long int N;
	cin >> N;
	UF<long long int>uf;
	vector<pair<long long int, long long int>>D( N ), E( N );
	for( size_t i = 0; i < N; i++ ) {
		cin >> D[i].first;
		D[i].second = i;
		cin >> E[i].first;
		E[i].second = i;
		uf.push( i );
	}
	sort( D.begin(), D.end() );
	sort( E.begin(), E.end() );

	priority_queue<pair<long long int, pair<long long int, long long int>>, vector<pair<long long int, pair<long long int, long long int>>>, greater<pair<long long int, pair<long long int, long long int>>>>que;
	for( size_t i = 0; i < N - 1; i++ ) {
		que.push( make_pair( D[i + 1].first - D[i].first, make_pair( D[i + 1].second, D[i].second ) ) );
		que.push( make_pair( E[i + 1].first - E[i].first, make_pair( E[i + 1].second, E[i].second ) ) );
	}
	long long int ans = 0;
	while( que.size() ) {
		auto now = que.top(); que.pop();
		if( !uf.same( now.second.first, now.second.second ) ) {
			uf.merge( now.second.first, now.second.second );
			ans += now.first;
		}
	}
	cout << ans << endl;
}