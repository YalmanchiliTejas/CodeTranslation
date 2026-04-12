# include <bits/stdc++.h>
# define pf push_front
# define pb push_back
# define mp make_pair
# define pr printf
# define se second
# define si size()
# define sc scanf
# define fi first
# define er erase
# define be begin
# define ss size
# define Int __int64
# define INF 100000000000000008
# define MOD 1000000007
# define MN 500500
# define eps 0.0000000000000000018
# define mem(a) memset(a,0,sizeof(a))
# define cpy(b,a) memcpy(b,a,sizeof(a))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
using namespace std;

int main() {
	int r,b,g,ans;
	cin>>r>>b>>g;
	ans=b*10+g;
	if(ans%4)
		cout<<"NO";
	else cout<<"YES";
	return 0;
}
/* and its only us now */
