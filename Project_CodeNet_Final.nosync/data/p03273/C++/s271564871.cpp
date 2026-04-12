#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 105;
char g[maxn][maxn];
char h[maxn], w[maxn];

int main()
{
	memset(g, 0, sizeof(g));
	memset(h, 0, sizeof(h));
	memset(w, 0, sizeof(w));
	
	int H, W;	cin >> H >> W;
	for(int i = 0; i < H; i ++)
	{
		cin >> g[i];
		for(int j = 0; j < W; j ++)
			if(g[i][j] == '#')	h[i] = w[j] = 1;
	}
	
	for(int i = 0; i < H; i ++)
	{
		if(h[i] == 0)	continue;
		for(int j = 0; j < W; j ++)
		{
			if(w[j] == 0)	continue;
			cout << g[i][j];
		}
		cout << endl;
	}
}