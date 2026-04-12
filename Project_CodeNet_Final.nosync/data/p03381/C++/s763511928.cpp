#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
//#include <chrono> //1e+9で割る auto end= chrono::system_clock::now()-st;  cout<<end.count()%1e+9<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef long double db;

#define fr first
#define sc second
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)

ll N;
P X[200000];
ll id[200000];
ll v1,v2;
int main()
{
	cin>>N;
	rep(i,N){
		cin>>X[i].fr;
		X[i].sc=i;
	}
	sort(X,X+N);
	rep(i,N){
		id[X[i].sc]=i;
	}
	v1=X[N/2-1].fr;
	v2=X[N/2].fr;
	rep(i,N){
		if(id[i]<N/2) cout<<v2<<endl;
		else cout<<v1<<endl;
	}
}