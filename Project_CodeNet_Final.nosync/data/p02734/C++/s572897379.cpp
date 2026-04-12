#include<bits/stdc++.h>
using namespace std;

#define mo 998244353
#define MAXN 3005 
#define int long long

int n,m,S;
int s[MAXN],a[MAXN],c[MAXN],d[MAXN];

void rd()
{
	cin >> n >> S;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
}

signed main()
{
	rd();
//	c[0] = s[0] = 1;
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		c[0] ++;
		for(int j = S; j >= 0; j --)
			if(j+a[i] <= S) {
				c[j+a[i]] += c[j];
				if(c[j+a[i]] >= mo) c[j+a[i]] -= mo;
			}
		for(int j = 0; j <= S; j ++) {
			s[j] += c[j]; 
			if(s[j] >= mo) s[j] -= mo;
		}
		for(int j = 0; j <= S; j ++)
			d[j] += s[j];/*
		cout<<i<<"----\n";
		for(int j = 0; j <= S; j ++)
			cout<<c[j]<<" ";
		cout<<"\n";
		for(int j = 0; j <= S; j ++)
			cout<<s[j]<<" ";
		cout<<"\n\n";*/
	/*	cout<<"\n";
		for(int j = 0; j <= S; j ++)
			cout<<d[j]<<" ";
		cout<<"\n\n";*/
		
		
		ans += c[S];
		if(ans >= mo) ans -= mo;
	}
//	ans += c[S];
	cout<<ans%mo<<"\n";
	return 0;
}
/*
3 4
2 2 4
4 5
2 2 3 3 
*/