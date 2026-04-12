#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
#define X first
#define Y second

int main()
{
	
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	puts((100*r+10*g+b)%4==0?"YES":"NO");
	
	return 0;
}
