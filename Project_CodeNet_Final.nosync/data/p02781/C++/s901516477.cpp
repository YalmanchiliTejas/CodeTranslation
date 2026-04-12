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
const int N = (int)4e6 + 123;

int fact[N];

int mult(int a, int b)
{
	return 1ll * a * b % mod;
}

int add(int a, int b)
{
	a += b;
	if(a < 0) a += mod;
	if(a >= mod) a %= mod;
	return a;
}

int Binpow(int a, int n)
{
	if(!n) return 1;
	if(n & 1) return mult(Binpow(a, n - 1), a);
	else
	{
		int b = Binpow(a, n / 2);
		return mult(b, b);
	}
}

int C(int n, int k)       
{
	if(k > n) return 0;
	int up = fact[n];
	int down = mult(fact[k], fact[n - k]);
	return mult(up, Binpow(down, mod - 2));
}

string s;
int k;
long long ans;
set <string> d;

bool Compare(string s1, string s2)
{
	for(int i = 0; i < sz(s1); i++) 
	{
		if(s1[i] > s2[i]) return 1;
		else if(s2[i] > s1[i]) return 0;
	}
	return 0;
}
 
int main ()
{
	#ifdef JUDGE
		freopen("input.txt", "r", stdin);
	#endif	
	Fast_Read_Out();
	Random();   
	fact[0] = 1;
	for(int i = 1; i <= 1000000; i++) fact[i] = mult(fact[i - 1], i);
	cin >> s >> k;
	for(int sz = 1; sz <= sz(s) - 1; sz++) ans += 9 * C(sz - 1, k - 1) * Binpow(9, k - 1);
	if(k == 1) ans += max(s[0] - '0', 0);
	else if(k == 2)
	{           
		ans += max(s[0] - '0' - 1, 0) * (sz(s) - 1) * 9;
		string s1 = "";
		s1 += s[0];
		for(int i = 1; i < sz(s); i++) s1 += '0';
		for(int i = 1; i < sz(s); i++)
		{
			for(char a = '1'; a <= '9'; a++)
			{
				s1[i] = a;
				if(!Compare(s1, s)) ans++;
			}
			s1[i] = '0';																																				
		}
	}
	else
	{
		ans += max(s[0] - '0' - 1, 0) * 9 * 9 * C(sz(s) - 1, 2);
		string s1 = "";
		s1 += s[0];
		for(int i = 1; i < sz(s); i++) s1 += '0';
		for(int i = 1; i < sz(s); i++)
			for(int j = i + 1; j < sz(s); j++)
			{
				if(i == j) continue;
				for(char a = '1'; a <= '9'; a++)
					for(char b = '1'; b <= '9'; b++)
					{
						s1[i] = a;
						s1[j] = b;
						if(!Compare(s1, s)) ans++;
					}
				s1[i] = s1[j] = '0';
			} 
	}	
	cout << ans;
}                                