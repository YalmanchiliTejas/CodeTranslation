#define ll long long
#define ffor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define SIZE 100001
#define MOD 1000000007
#define INF 100000000
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int r,g,b;
	cin >> r >> g >> b;

	int ans = r*100+g*10+b;

	if(ans % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;


	return 0;
}