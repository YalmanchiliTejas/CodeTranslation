/* Author : tushar3105 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<long long int,long long int> ii;					// Pair of integers
typedef vector<long long int> vi;                   				// Vector of integers
typedef vector<vector<long long int>> vvi;                 			// Vector of vi
typedef vector<pair<long long int, long long int>> vii;				// Vector of ii

#define pb push_back								// Push back to vectors
#define mp make_pair								// For pairs
#define ff first								// For pairs
#define ss second								// For pairs
#define all(c) (c).begin(),(c).end()						// Use in sorting
#define sz(a) ((long long int)(a).size())
#define lli long long int
#define ull unsigned long long int
#define ld long double
#define ref(i,x,y) for(long long int i=(x);i<=(y);++i)				// Loop to go forward
#define reb(i,x,y) for(long long int i=(x);i>=(y);--i)				// Loop to go backward
#define trf(c,it) for(auto it = (c).begin(); it != (c).end(); it++)		// Remember it is an iterator
#define trb(c,it) for(auto it = (c).end()-1; it != (c).begin()-1; it--)		// Remember it is an iterator
#define tc(t) long long int t; cin>>t;while(t--)				// Test cases
//fill (dist,dist+110000,pinf);							// For setting default

const long long int mod = 1e9+7;
const long long int pinf = 9223372036854775807;
const long long int ninf = -9223372036854775807;

/*-----------------------------Code begins----------------------------------*/

int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	lli x;
	
	cin>>x;
	
	if (x>=30)
		cout<<"Yes\n";
		
	else
		cout<<"No\n";

	return 0;
}
