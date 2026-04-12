#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair< int , int >
#define vii vector<ii>
#define FOR(i, n) for(ll i = 0; i < (ll)n; i++)
int MAX(int a, int b){return (a > b) ? a:b;}
int MIN(int a, int b){return (a < b) ? a:b;}
int ABS(int x){return (x > 0) ? x:-x;}
int left(int x){return (x<<1);}
int right(int x){return (x<<1)+1;}
int lsone(int x){return (x&(-x));}

const int maxn = 3e3 + 5;

int n, a[maxn];
ll ans[maxn][maxn][2];
bool found[maxn][maxn][2];

ll dp(int l, int r, bool turn){
	if(r < l) return 0;
	if(found[l][r][turn]) return ans[l][r][turn];
	found[l][r][turn] = true;
	if(turn){//Minimize diff
		ll tmp1 = dp(l+1, r, 1-turn)-a[l];
		ll tmp2 = dp(l, r-1, 1-turn)-a[r];
		ans[l][r][turn] = min(tmp1, tmp2);
	}else{
		ll tmp1 = dp(l+1, r, 1-turn)+a[l];
		ll tmp2 = dp(l, r-1, 1-turn)+a[r];
		ans[l][r][turn] = max(tmp1, tmp2);
	}
	return ans[l][r][turn];
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	printf("%lld\n", dp(0, n-1, 0));
}