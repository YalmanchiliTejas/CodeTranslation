#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
ll l[51], p[51];
ll solve(int n, ll x){
	if(n==0) return 1;
	if(x==1) return 0;
	if(x<=l[n-1]+1) return solve(n-1, x-1);
	if(x==l[n-1]+2) return p[n-1]+1;
	if(x<=2+2*l[n-1]) return p[n-1]+1+solve(n-1, x-2-l[n-1]);
	return p[n-1]*2+1;
}
int main()
{
	int n; ll x;
	cin>>n>>x;
	l[0]=1, p[0]=1;
	for(int i=1; i<=n; i++){
		l[i]=2*l[i-1]+3;
		p[i]=2*p[i-1]+1;
	}
	cout<<solve(n, x)<<endl;
	return 0;
}