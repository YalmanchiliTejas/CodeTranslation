#include <bits/stdc++.h>	
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ld long double
#define pii pair <int, int>
#define sz(a) (int)(a.size()) 
#define resize(v) v.resize(unique(all(v)) - v.begin()); 
#define all(a) a.begin(), a.end()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)

// random_device rd; mt19937 g(rd());    
                                        	
using namespace std;
using namespace __gnu_pbds;
 
void Fast_Read_Out()
{
    ios_base::sync_with_stdio(0);
    cin.tie(), cout.tie();
}
 
void Random()
{
    unsigned int seed;                                                                        
    asm("rdtsc" : "=A" (seed));
    srand(seed);        
}
 
unsigned int Time()
{
     unsigned int time = clock() / 1000.00;                           
     return time;
}

template <typename T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
const int mod = (int)1e9 + 7;
 
int main ()
{
	#ifdef JUDGE
		freopen("input.txt", "r", stdin);
	#endif		
	Fast_Read_Out();
	Random();   
	int n, m;
	cin >> n >> m;
	if(n == m) cout << "Yes";
	else cout << "No";
}                                