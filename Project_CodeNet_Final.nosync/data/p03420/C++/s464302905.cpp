#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(void)
{
	int x = 0,f = 1; char ch = getchar();
	while(!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
	return x * f;
}
signed main(signed argc, char *argv[])
{
	int ans = 0;
	int N = read(),K = read();
	if (K == 0)
	{
		N *= N;
		cout << N;
		return 0;
	}
	for (int b = K+1; b <= N; b++)
	{
		int xmax = (N)/(b);
		//cout << xmax << " # " << "\n"; 
		ans += xmax * (b-K);
		ans += max(0LL,(N - b * xmax) - K + 1);
		//cout << ans << endl;
	}
	cout << ans;
	return 0;
}
