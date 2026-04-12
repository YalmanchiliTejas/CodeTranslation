#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define UP(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define UU(a,b,c) for(ll (a)=(b);(a)<=(c);(a)++)
#define DN(a,b,c) for(ll (a)=(b);(a)>(c);(a)--)
#define DU(a,b,c) for(ll (a)=(b);(a)>=(c);(a)--)


int n;

void reset()
{
}

void input()
{
	cin>>n;
}

void solve()
{
	cout<<(n >= 30? "Yes":"No")<<endl;
}

void LetsRock()
{
	solve();	
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	input();
	reset();
	LetsRock();
	
	return 0;
}
