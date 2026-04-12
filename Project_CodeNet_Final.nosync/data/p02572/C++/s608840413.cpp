#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<iterator>
using namespace std;

void dfs(int vertex,vector <vector <int>>& adj, vector <int>& colour, int present_colour, int& count, vector <int> &visited)
{
	if (present_colour != colour[vertex])
	{
		count++;
		present_colour = colour[vertex];
	}
	for (int i = 0; i < adj[vertex].size(); i++)
	{
		int child = adj[vertex][i];
		if (visited[child] == 0)
		{
			visited[child] = 1;
			dfs(child, adj, colour, present_colour, count, visited);
		}
	}
}

int main() {

	int n;
	cin >> n;
	vector <long long> arr(n+5);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector <long long> sum(n+5);
	long long mod = 1000000007;
	sum[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		sum[i] = (sum[i + 1] + arr[i])%mod;
	}
	
	long long ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ans = (ans+ (arr[i] * (sum[i + 1])) % mod)%mod;
	}
	cout << ans;

	return 0;
}


