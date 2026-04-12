#include	<bits/stdc++.h>
using	namespace	std;
typedef	long long ll;

// int/long:		-2,147,483,648 - 2,147,483,647 (-2^31 <= int < 2^31)
// long/long long:	-9,223,372,036,854,775,808 - 9,223,372,036,854,775,807 (-2^63 <= long < 2^63)

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

//
// Notes
//
// When specified less than N, try full scan.
// RE: empty vector
// Check Qs
// long/int
// xor -> count each bit
// Check values
// 	1,000,000 -> Loop
// 	100,000	-> vector(int:400KB, long:800KB) 

#define	INF (1<<30)
//1,073,741,824
//= 536,870,912 *2

#define	MOD 1000000007

#define	Rep0(i, n)	for (int i=0; i<n; i++)
#define	Rep1(i, n)	for (int i=1; i<=n; i++)
#define Sort(P)	sort(P.begin(), P.end())
#define Rev(P)	reverse(P.begin(), P.end())

int	main() {
	string S;
	int K;
	cin >>S >>K;
	int N=S.size();
	vector<int> A;
	A.push_back(0);
	Rep0(i, N)
		A.push_back(S.at(i)-'0');
	N++;
	vector<vector<int>>	DPOK(N, vector<int> (K+1, 0));
	vector<vector<int>>	DPUK(N, vector<int> (K+1, 0));
	DPUK.at(0).at(K)=1;
	Rep0(i, N-1) {
		Rep0(k, K+1) {
			// for DPOK
			DPOK.at(i+1).at(k) +=DPOK.at(i).at(k);			// next 0
			if (k>0)
				DPOK.at(i+1).at(k-1) +=DPOK.at(i).at(k)*9;	// next 1-9
			// for DPUK
			if (0==A.at(i+1)) {
				DPUK.at(i+1).at(k) +=DPUK.at(i).at(k);		// next =0, still unknown
			} else { // 0<A.at(i+1)
				DPOK.at(i+1).at(k) +=DPUK.at(i).at(k);		// next =0, OK
				if (k>0) {
					DPOK.at(i+1).at(k-1) +=DPUK.at(i).at(k)*(A.at(i+1)-1);	// next =1 - A(i+1)-1, OK
					DPUK.at(i+1).at(k-1) +=DPUK.at(i).at(k);	// next =A(i+1), unknown
				}
			}
		}
	}
	int SS=DPOK.at(N-1).at(0)+DPUK.at(N-1).at(0);
	cout <<SS <<endl;
	return 0;
}

