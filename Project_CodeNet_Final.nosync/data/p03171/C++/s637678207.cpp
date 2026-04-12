#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;


int N;
int a[3003];
ll pd[3003][3003];
bool calc[3003][3003];

ll solve(int i, int j){
	if(i==j)  return a[i];
	if(i>j) return 0;
	if(calc[i][j]) return pd[i][j]; calc[i][j] = 1;
	ll aa = min(solve(i+2, j)+a[i], solve(i+1, j-1)+a[i]);
	ll bb = min(solve(i, j-2)+a[j], solve(i+1, j-1)+a[j]);
	return pd[i][j] = max(aa, bb);
}

int main(){

	cin >> N; ll tt = 0;
	rep(i, 0, N) cin >> a[i], tt+=a[i];
	
	memset(pd, -1, sizeof pd);
	
	ll X = solve(0, N-1);
	
	cout << X - (tt-X) << '\n';
	
	return 0;
}