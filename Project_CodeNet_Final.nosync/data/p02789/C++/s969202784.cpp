#include	<bits/stdc++.h>
using	namespace	std;

// int/long:		-2,147,483,648 - 2,147,483,647 (-2^31 <= int < 2^31)
// long/long long:	-9,223,372,036,854,775,808 - 9,223,372,036,854,775,807 (-2^63 <= long < 2^63)

#define	INF (1<<30)
//1,073,741,824
//= 536,870,912 *2

#define	MOD 1000000007

// lower_bound(A.begin(), A.end(), N)
// upper_bound(...

// A.erase(unique(A.begin(), A.end()), A.end())

// bit: &/and, |/or, ^/xor, ~/not

// getline(cin, String)
// while (getline(cin, S)) {}

// cout <<fixed <<setprecision(10)

// priority_queue<int> q;
// priority_queue<int, vector<int>, less<int>> q; // Default: vector, less
// priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

// Graph
// Warshall-Floyd: Distance between each node, N^3
// Dijkstra: Distance from the start node, N^2
// DFS(Depth-First Search)

/*
int	gcd(int A, int B) {
	while (0!=B) {
		A %=B;
		swap(A, B);
	}
	return A;
}

long	gcd(long A, long B) {
	while (0!=B) {
		A %=B;
		swap(A, B);
	}
	return A;
}

long	lcm(long A, long B) {
	long G=gcd(A, B);
	return A/G*B;
}

long	GCD(vector<long> &A) {
	long B=A.at(0);
	for (long i=1; i<A.size(); i++)
		B =gcd(B, A.at(i));
	return B;
}

long	LCM(vector<long> &A) {
	long B=A.at(0);
	for (long i=1; i<A.size(); i++)
		B =lcm(B, A.at(i));
	return B;
}
*/

int	main() {
	int N, M;
	cin >>N >>M;
	if (N==M)
		cout <<"Yes" <<endl;
	else
		cout <<"No" <<endl;
	return 0;
}

