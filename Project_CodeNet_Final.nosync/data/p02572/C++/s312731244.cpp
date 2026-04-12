#include<bits/stdc++.h>
#define MAXN 300005
typedef long long ll;
using namespace std;

int n;
ll p = 1e9 + 7,a[MAXN],sum[MAXN],ans = 0;

inline int read()
{
	char c = getchar(); int res = 0;
	while(c < '0' || c >'9') c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

int main(){
	
	n = read();
	for(int i = 1 ; i <= n ; i++)a[i] = read();
	for(int i = n ; i >= 1 ; i--)sum[i] = (sum[i + 1] + a[i]) % p;
	for(int i = 1 ; i <= n ; i++){
		ans = (ans + a[i] * sum[i + 1]) % p;
	}
	cout<<ans<<endl;
}