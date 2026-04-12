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
int main()
{
	int n;lint a,out=0,N;
	vector<lint> v;
	cin>>n;N=n;
	rep(i,n){
		cin>>a;v.pb(a);
	}
	sort(All(v));
	while(v[n-1]>=N){
		lint sum=0;
		vector<lint> x,ne;
		rep(i,n){
			if(v[i]>N-1) x.pb(v[i]/N);
			else x.pb(0);
			sum+=x[i];
		}
		rep(i,n){
			v[i]-=N*x[i];
			v[i]+=(sum-x[i]);
		}
		out+=sum;sort(All(v));
	}
	cout<<out<<endl;
}
