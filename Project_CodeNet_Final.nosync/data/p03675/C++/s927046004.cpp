#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int a[214514],b[214514];
int main()
{
	int n;
	cin>>n;
	int x=0,y=n-1;
	rep(i,n) cin>>a[i];
	for(int i=n-1;i>=0;i--){
		if(i%2==n%2){
			b[y]=a[i];y--;
		}
		else{
			b[x]=a[i];x++;
		}
	}
	rep(i,n){
		cout<<b[i];
		if(i<n-1) cout<<' ';else cout<<endl;
	}
}
