#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

ll N, res;
int X, M;
int g[100101], in[100101];
bool vis[101001];
ll S[100101];

int main()
{
	scanf("%lld %d %d", &N, &X, &M);
	for(int i=0; i<=M; i++)
	{
		g[i] = (int)((ll)i*i%M);
		in[g[i]]++;
	}
	queue<int> q;
	for(int i=0; i<=M; i++)
		if (in[i] == 0)
			q.push(i);
	while(!q.empty())
	{
		int n = q.front(); q.pop();
		if (--in[g[n]] == 0)
			q.push(g[n]);
	}
	// 사이클에 들어갈 때까지 이동
	int cnt = 0, x = X;
	while(1)
	{
		if (in[x]) break;
		N--;
		res += x;
		x = g[x];
		if (N == 0) return !printf("%lld", res);
	}
	while(1)
	{
		if (vis[x]) break;
		vis[x] = true;
		cnt++;
		S[cnt] = S[cnt-1] + x;
		x = g[x];
	}
	res += S[cnt]*(N/cnt);
	N %= cnt;
	res += S[N];
	printf("%lld", res);
	return 0;
}