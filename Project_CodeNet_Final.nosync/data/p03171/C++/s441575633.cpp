#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <map>

using namespace std;

//A
//int main()
//{
// int n, h;
// std::vector<int> heights;
//
// cin >> n;
// for (int i = 0; i < n; ++i)
// {
//  cin >> h;
//  heights.push_back(h);
// }
//
// vector<int> m(n, 0);
// m[0] = 0;
// m[1] = abs(heights[1] - heights[0]);
//
// for (int i = 2; i < n; ++i)
// {
//  m[i] = min(m[i - 2] + abs(heights[i] - heights[i - 2]), m[i - 1] + abs(heights[i] - heights[i - 1]));
// }
//
// cout << m[n - 1];
//}


//B
//int main()
//{
// int n, k, h;
// std::vector<int> heights;
//
// cin >> n >> k;
// for (int i = 0; i < n; ++i)
// {
//  cin >> h;
//  heights.push_back(h);
// }
//
// vector<int> m(n, 0);
// m[0] = 0; 
//
// for (int i = 1; i < n; ++i)
// {
//  int m_min = INT_MAX;
//  for (int j = 1; j <= k; ++j)
//  {
//   if (i - j < 0) break;
//   int m_cur = m[i - j] + abs(heights[i] - heights[i - j]);
//   if (m_cur < m_min) m_min = m_cur;
//  }
//  m[i] = m_min;
// }
//
// cout << m[n - 1];
//}

//C
//int main()
//{
//    size_t n;
//    cin >> n;
//    vector<vector<int>> activities;
//
//    int a, b, c;
//    for (size_t i = 0; i < n; ++i)
//    {
//        cin >> a >> b >> c;
//        vector<int> acts;
//        acts.push_back(a);
//        acts.push_back(b);
//        acts.push_back(c);
//        activities.push_back(acts);
//    }
//
//    vector<vector<int>> m(n, vector<int>(3, 0));
//
//	for (int j = 0; j < 3; ++j)
//	{
//        m[0][j] = activities[0][j];
//	}
//
//    for (size_t i = 1; i < n; ++i)
//    {
//        m[i][0] = activities[i][0] + max(m[i - 1][1], m[i - 1][2]);
//        m[i][1] = activities[i][1] + max(m[i - 1][0], m[i - 1][2]);
//        m[i][2] = activities[i][2] + max(m[i - 1][0], m[i - 1][1]);
//    }
//
//    cout << *max_element(m[n-1].begin(), m[n-1].end());
//}

//D
//int main()
//{
//    int n, W;
//    cin >> n >> W;
//    vector<int> weights;
//    vector<long long> values;
//
//    int w, v;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> w >> v;
//        weights.push_back(w);
//        values.push_back(v);
//    }
//
//    vector<vector<long long>> m(n + 1, vector<long long>(W + 1, 0));
//
//    for (int j = 0; j <= W; ++j)
//    {
//        m[0][j] = 0;
//    }
//
//    for (int i = 1; i <=n; ++i)
//    {
//        int index = i - 1;
//	    for (int j = 0; j <= W; ++j)
//	    {
//		    if (weights[index] > j)
//		    {
//                m[i][j] = m[i - 1][j];
//		    }
//            else
//            {
//                m[i][j] = max(m[i - 1][j], m[i - 1][j - weights[index]] + values[index]);
//            }
//	    }
//    }
//
//    cout << m[n][W];
//}


//E
//int main()
//{
//	int n;
//	long long W;
//	cin >> n >> W;
//	vector<long long> weights;
//	vector<int> values;
//
//	long w;
//	int v;
//	int MAX_V = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> w >> v;
//		weights.push_back(w);
//		values.push_back(v);
//		MAX_V += v;
//	}
//
//	//const int MAX_V = 10;
//	vector<vector<long long >> m(n + 1, vector<long long>(MAX_V + 1, 0));
//	m[0][0] = 0;
//	for (int j = 1; j <= MAX_V; ++j)
//	{
//		m[0][j] = W + 1;
//	}
//
//
//	for (int i = 1; i <= n; ++i)
//	{
//		int index = i - 1;
//		for (int j = 0; j <= MAX_V; ++j)
//		{
//			if (values[index] > j)
//			{
//				m[i][j] = m[i - 1][j];
//			}
//			else
//			{
//				m[i][j] = min(m[i - 1][j], m[i - 1][j - values[index]] + weights[index]);
//			}
//		}
//	}
//
//	int max_value = -1;
//	for (int j = 0; j <= MAX_V; ++j)
//	{
//		if (m[n][j] != W + 1) max_value = j;
//	}
//
//	cout << max_value;
//}

//int lcs(const string&  x, const string& y, int m, int n)
//{
//	if (m == 0 || n == 0) return 0;
//	if (x[m - 1] == y[n - 1]) return 1 + lcs(x, y, m - 1, n - 1);
//	return max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
//}

//F
//int main()
//{
//	string s, t;
//	cin >> s >> t;
//
//	//int res = lcs(s, t, s.length(), t.length());
//
//	vector<vector<int>> m(s.length() + 1, vector<int>(t.length() + 1, 0));
//	/*for (size_t i = 0; i <= s.length(); ++i)
//	{
//		m[i][0] = "";
//	}
//
//	for (size_t j = 0; j <= t.length(); ++j)
//	{
//		m[0][j] = "";
//	}*/
//
//	size_t sl = s.length();
//	size_t tl = t.length();
//
//	for (size_t i = 1; i <= sl; ++i)
//	{
//		for (size_t j = 1; j <= tl; ++j)
//		{
//			if (s[i - 1] == t[j - 1])
//			{
//				m[i][j] = m[i - 1][j - 1] + 1;
//			}				
//			else
//			{
//				if (m[i - 1][j] >= m[i][j - 1])
//				{
//					m[i][j] = m[i - 1][j];
//				}
//				else
//				{
//					m[i][j] = m[i][j-1];
//				}
//			}
//		}
//	}
//
//	string res = "";
//	size_t i = s.length();
//	size_t j = t.length();
//	while (i > 0 && j > 0)
//	{
//		if (m[i][j] == m[i][j - 1])
//			j--;
//		else if (m[i][j] == m[i - 1][j])
//			i--;
//		else
//		{
//			res = s[i - 1] + res;
//			i--;
//			j--;
//		}
//	}
//	
//	cout << res;
//	
//}


//G
//void dfs(int node, const vector<vector<int>>& adj, vector<bool>& vis, vector<int>& depths)
//{
//	vis[node] = true;
//
//	for (int i = 0; i < adj[node].size(); ++i)//children
//	{
//		const int child_node = adj[node][i];
//		
//		if (!vis[child_node])
//			dfs(child_node, adj, vis, depths);
//
//		depths[node] = max(depths[node], 1 + depths[child_node]);
//	}	
//}
//
//
//int main()
//{
//	int n, m;
//	
//	cin >> n >> m;
//
//	
//	vector<vector<int>> adj(n, vector<int>());
//	int xi, yi;
//	
//	
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> xi >> yi;		
//		adj[xi-1].push_back(yi-1);
//	}
//
//	vector<bool> vis(n, false);
//	vector<int> depths(n, 0);
//
//	for (int i = 0; i < n; ++i)
//	{
//		if (vis[i]) continue;
//		dfs(i, adj, vis, depths);
//	}
//
//	cout << *max_element(depths.begin(), depths.end());
//		
//}



//H
//int main()
//{
//	int H, W;
//
//	cin >> H >> W;
//
//	vector<string> grid;
//	string s;
//	for (int i = 0; i < H; ++i)
//	{
//		cin >> s;
//		grid.push_back(s);
//	}
//
//	vector<vector<int>> dp(H + 1, vector<int>(W + 1));
//	for (int i = 0; i <= H; ++i)
//	{
//		dp[i][0] = 0;
//	}
//	for (int j = 0; j <= W; ++j)
//	{
//		dp[0][j] = 0;
//	}
//
//
//	for (int i = 1; i <= H; ++i)
//	{
//		for (int j = 1; j <= W; ++j)
//		{
//			if (i == 1 && j == 1)
//				dp[i][j] = 1;
//			else if (grid[i-1][j-1] == '#')
//				dp[i][j] = 0;
//			else
//				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % (1000000007);
//		}
//	}
//
//	cout << dp[H][W];
//
//}


//void get_variants(int size, const vector<int>& cur_var, vector<vector<int>>& all_vars)
//{
//	if (cur_var.size() == size)
//	{
//		all_vars.push_back(cur_var);
//		return;
//	}
//
//	//0
//	vector<int> new_var = cur_var;
//	new_var.push_back(0);
//	get_variants(size, new_var, all_vars);
//
//	//1
//	new_var = cur_var;
//	new_var.push_back(1);
//	get_variants(size, new_var, all_vars);
//}


//I
//int main()
//{
//
//
//	int n;
//	cin >> n;
//
//	vector<double> p(n);
//	double pi;
//
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> pi;
//		p[i] = pi;
//	}
//
//
//	//pd[i][j] - вероятность получить j heads в i монетах
//
//	vector<vector<double>> dp(n + 1, vector<double>(n + 1));
//	dp[0][0] = 1.0;
//
//	// Iterating for every coin 
//	for (int i = 1; i <= n; ++i)
//	{
//		const auto prob = p[i - 1];
//		// j represents the numbers of heads
//		for (int j = 0; j <= i; ++j)
//		{
//			// If number of heads is equal to zero 
//			// there there is only one possiblity 
//			if (j == 0)
//			{
//				dp[i][j] = dp[i - 1][j] * (1 - prob);
//			}
//			else
//			{
//				dp[i][j] = dp[i - 1][j] * (1 - prob) + dp[i - 1][j - 1] * prob;
//			}
//		}
//	}
//
//	double res = 0.0;
//	// When the number of heads is greater than (n+1)/2 
//	// it means that heads are greater than tails as 
//	// no of tails + no of heads is equal to n for 
//	// any permuation of heads and tails
//
//	for (int j = (n + 1) / 2; j <= n; ++j)
//		res += dp[n][j];
//
//	cout.precision(10);
//	cout << res;
//
//}


//J
//int main()
//{
//    const int SIZE = 310;
//    double dp[SIZE][SIZE][SIZE];
//
//    int n;
//    cin >> n;
//
//    vector<int> a(n);
//    double ai;
//
//    int c1 = 0, c2 = 0, c3 = 0;
//
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> ai;
//        a[i] = ai;
//        if (ai == 1) c1++;
//        else if (ai == 2) c2++;
//        else c3++;
//    }
//
//
//    //pd[i][j][k] - ожидаемое число ходов до конца, если осталось
//    //i размера 1
//    //j размера 2
//    //k размера 3
//
//   
//    dp[0][0][0] = 0;
//
//    for (int k = 0; k < SIZE; ++k)
//    {
//        for (int j = 0; j + k < SIZE; ++j)
//        {
//            for (int i = 0; i + j + k < SIZE; ++i)
//            {
//                if (i == 0 && j == 0 && k == 0) continue;
//                double pi = 1.0 * i / (i + j + k);
//                double pj = 1.0 * j / (i + j + k);
//                double pk = 1.0 * k / (i + j + k);
//
//                if (i)
//                    dp[i][j][k] += pi * dp[i - 1][j][k];
//                if (j)
//                    dp[i][j][k] += pj * dp[i + 1][j - 1][k];
//                if (k)
//                    dp[i][j][k] += pk * dp[i][j + 1][k - 1];
//
//                dp[i][j][k] += 1.0 * n / (i + j + k);//выкинули номер с пустой тарелкой
//            }
//        }
//    }
//
//    cout.precision(10);
//    cout << dp[c1][c2][c3];
//
//}


//K
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	vector<int> a(n);
//	int ai;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> ai;
//		a[i] = ai;
//	}
//
//	//dp[i] - TRUE if first player wins if there are i stones remaining
//
//	vector<bool> dp(k + 1, false);
//	for (int stones = 0; stones <=k; ++stones)
//	{
//		for (int x :a)
//		{
//			if (stones >= x && !dp[stones-x])
//			{
//				dp[stones] = true;
//			}
//		}
//	}
//	
//	cout << (dp[k] ? "First" : "Second");	
//	
//	return 0;
//}


//L
int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	int ai;
	for (int i = 0; i < n; ++i)
	{
		cin >> ai;
		a[i] = ai;
	}

	//dp[i][j] - выигрыш текущего игрока при положении левого указателя - i и правого - j

	const int nax = 3005;
	long long dp[nax][nax];

	for (int l = n-1; l >= 0; --l)
	{
		for (int r = l; r < n; ++r)
		{
			if (l == r)
				dp[l][r] = a[l];
			else
				dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
		}
	}
	

	cout << dp[0][n-1];

	return 0;
}