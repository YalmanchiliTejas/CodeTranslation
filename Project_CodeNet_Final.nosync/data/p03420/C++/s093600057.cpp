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
lint cal(lint n,lint b,lint k){
	if(k==0LL) return n;
	lint ret=(n/b)*(b-k);
	if(n%b>=k) ret+=n%b-k+1;
	return ret;
}
int main()
{
	int n,k;lint out=0;cin>>n>>k;
	REP(i,k+1,n+1){
		out+=cal(n,i,k);
		//cout<<i<<' '<<cal(n,i,k)<<endl;
	}
	cout<<out<<endl;
}
