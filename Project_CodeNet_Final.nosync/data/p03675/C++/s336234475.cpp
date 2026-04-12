#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
#include<numeric>
using namespace std;
typedef long long int lli;
#define rep(i,n) for(lli i = 0;i<((lli)(n));i++)
#define reg(i,a,b) for(lli i = ((lli)(a));i<=((lli)(b));i++)
#define irep(i,n) for(lli i = ((lli)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(lli i = ((lli)(b));i>=((lli)(a));i--)
typedef pair<lli, lli> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprllif(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))

int main(void){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	
	for(int i = n-1 ; i >= 0 ; i -= 2) cout << a[i] << " ";
	for(int i = n%2 ; i <= n-2 ; i += 2) cout << a[i] << (i >= n-3 ? "" : " ");
	cout << endl;
	
	return 0;
}