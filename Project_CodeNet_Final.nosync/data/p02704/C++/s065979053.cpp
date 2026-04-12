#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
struct custom_hash 
{
    static unsigned long long splitmix64(unsigned long long x) 
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(unsigned long long x) const 
    {
        static const unsigned long long FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
mt19937 random_generator(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1003; 

int n; 
bool s[maxn], t[maxn];
unsigned long long u[maxn], v[maxn];
unsigned long long ans[maxn][maxn];
void read()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	cin >> s[i];
	
	for (int i = 1; i <= n; i++)
	cin >> t[i];
	
	for (int i = 1; i <= n; i++)
	cin >> u[i];
	
	for (int i = 1; i <= n; i++)
	cin >> v[i];
}

int curr_ans[maxn][maxn];
void solve_bit(int x)
{
	bool is_sat[maxn];
	memset(is_sat, false, sizeof(is_sat)); 
	memset(curr_ans, -1, sizeof(curr_ans));
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 0 && (u[i] & (1ull << x)))
		{
			for (int j = 1; j <= n; j++)
			{
				if (curr_ans[i][j] == 0)
				{
					cout << -1 << endl;
					exit(0);
				}
				
				curr_ans[i][j] = 1; 
			}
			
			is_sat[i] = true;
		}
		
		if (s[i] == 1 && !(u[i] & (1ull << x)))
		{
			for (int j = 1; j <= n; j++)
			{
				if (curr_ans[i][j] == 1)
				{
					cout << -1 << endl;
					exit(0);
				}
				curr_ans[i][j] = 0; 
			}
			
			is_sat[i] = true; 
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (t[i] == 0 && (v[i] & (1ull << x)))
		{
			for (int j = 1; j <= n; j++)
		    {
				if (curr_ans[j][i] == 0)
				{
					cout << -1 << endl;
					exit(0);
				}
				
				curr_ans[j][i] = 1; 
			}
			
			is_sat[i+n] = true; 
		}
		
		if (t[i] == 1 && !(v[i] & (1ull << x)))
		{
			for (int j = 1; j <= n; j++)
			{
			    if (curr_ans[j][i] == 1)
				{
					cout << -1 << endl;
					exit(0);
				}
				
				curr_ans[j][i] = 0; 
			}
			
			is_sat[i+n] = true; 
		}
	}
	
	vector <int> adj[maxn];
	int deg[maxn];
	memset(deg, 0, sizeof(deg)); 
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	if (curr_ans[i][j] == -1)
	{
		adj[i].push_back(j+n);
		adj[j+n].push_back(i);
		
		deg[i]++;
		deg[j+n]++; 
	}
	
	bool need[maxn]; 
	memset(need, false, sizeof(need)); 
	set <pair <int, int> > pending;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 0 && !(u[i] & (1ull << x)))
		{
			bool is = false;
			for (int j = 1; j <= n; j++)
			if (curr_ans[i][j] == 0)
			{
				is = true;
				break;
			}
			
			if (!is)
			{
				need[i] = 0; 
			    pending.insert({deg[i], i});
		    }
		    
		    else
		     is_sat[i] = true; 
		}
		
		if (s[i] == 1 && (u[i] & (1ull << x)))
		{
			bool is = false;
			for (int j = 1; j <= n; j++)
			if (curr_ans[i][j] == 1)
			{
				is = true;
				break; 
			}
			
			if (!is)
			{
				need[i] = 1;
			    pending.insert({deg[i], i});
		    }
		    
		    else
		     is_sat[i] = true; 
		}
	}
	
    for (int i = 1; i <= n; i++)
	{
		if (t[i] == 0 && !(v[i] & (1ull << x)))
		{
			bool is = false;
			for (int j = 1; j <= n; j++)
			if (curr_ans[j][i] == 0)
			{
				is = true;
				break;
			}
			
			if (!is)
		    {
				need[i+n] = 0; 
			    pending.insert({deg[i+n], i+n});
			}
			
			else 
			is_sat[i+n] = true; 
		}
		
		if (t[i] == 1 && (v[i] & (1ull << x)))
		{
			bool is = false;
			for (int j = 1; j <= n; j++)
			if (curr_ans[j][i] == 1)
			{
				is = true;
				break;
			}
			
			if (!is)
			{
				need[i+n] = 1; 
		     	pending.insert({deg[i+n], i+n});
			}
			
			else 
			is_sat[i+n] = true; 
		}
	}
	
	bool used_edge[maxn][maxn];
	memset(used_edge, false, sizeof(used_edge)); 
	while (!pending.empty())
	{
		auto curr = *pending.begin(); 
		pending.erase(pending.begin()); 
		
		if (deg[curr.second] == 0)
		{
			cout << -1 << endl;
			exit(0);
		}
		
		is_sat[curr.second] = true; 
		for (auto i: adj[curr.second])
		if (!used_edge[curr.second][i])
		{
			used_edge[curr.second][i] = used_edge[i][curr.second] = true; 
			if (curr.second > n)
			curr_ans[i][curr.second-n] = need[curr.second]; 
				
			else
			 curr_ans[curr.second][i-n] = need[curr.second];
			
			if (!is_sat[i])
			{
				pending.erase({deg[i], i});
				deg[i]--;
				
				if (need[i] != need[curr.second])
			     pending.insert({deg[i], i});
				 
			    else
				is_sat[i] = true; 
			}
			
			break;
		}
	}
	
	for (int i = 1; i <= 2 * n; i++)
	if (!is_sat[i])
	{
		cout << -1 << endl;
		exit(0);
	}
	
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	if (curr_ans[i][j] == 1)
	ans[i][j] += (1ull << x); 
}

void solve()
{
	for (int i = 0; i <= 63; i++)
	solve_bit(i);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		cout << ans[i][j] << " ";
		
		cout << endl;  
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	read();
	solve();
}
