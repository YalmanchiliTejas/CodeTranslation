#include <bits/stdc++.h>
using namespace std;

class adj_list {
	vector<vector<int>> m_vt;

public:
	explicit adj_list( int s ): m_vt( s+1 ) {}

	void add_edge( int a, int b ) {
		m_vt[a].push_back( b );
		m_vt[b].push_back( a );
	}

	int find_path() const {
		vector<bool> vf( m_vt.size()+1 );
		vf[1] = true;
		return dfs( 1, 1, vf );
	}

	int dfs( int nd, int nv, vector<bool>& vf ) const {
		if( nv == m_vt.size()-1 ) {
			return 1;
		}

		int result = 0;
		auto& ed = m_vt[nd];

		for( int i = 0; i < ed.size(); ++i ) {
			if( !vf[ed[i]] ) {
				vf[ed[i]] = true;
				result += dfs( ed[i], nv+1, vf );
				vf[ed[i]] = false;
			}
		}

		return result;
	}
};

int main() {
	ios_base::sync_with_stdio( false );

	int N, M;
	cin >> N >> M;

	adj_list al( N );
	for( int i = 0; i < M; ++i ) {
		int a, b;
		cin >> a >> b;

		al.add_edge( a, b );
	}

	cout << al.find_path() << endl;
}
