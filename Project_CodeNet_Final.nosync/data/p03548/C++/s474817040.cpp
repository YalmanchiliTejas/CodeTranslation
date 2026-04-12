#include	<bits/stdc++.h>
using	namespace	std;

// int/long:		-2,147,483,648 - 2,147,483,648 (-2^31 <= int < 2^31)
// long/long long:	-9,223,372,036,854,775,808 - 9,223,372,036,854,775,807 (-2^63 <= long < 2^63)

#define	INF (1<<29)
//536,870,912

// lower_bound(A.begin(), A.end(), N)
// upper_bound(...

// A.erase(unique(A.begin(), A.end()), A.end())

// bit: &/and, |/or, ^/xor, ~/not

// getline(cin, String)

// Graph
// Warshall-Floyd: Distance between each node, N^3
// Dijkstra: Distance from the start node, N^2
// DFS(Depth-First Search)

#define	MOD 1000000007

int	main() {
	int X, Y, Z;
	cin >>X >>Y >>Z;
	cout <<(X-Z)/(Y+Z) <<endl;
	return 0;
}

