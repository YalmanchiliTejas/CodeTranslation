#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
const int Maxn=200005;
pair<pair<int,int>,int> x[Maxn];
int n;
set<int> X,Y;
vector<pair<int,pair<int,int> > > e;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>, int> b){
	return a.first.second<b.first.second;
}
bool cmp1(pair<pair<int,int>,int> a,pair<pair<int,int>, int> b){
	return a.first.first<b.first.first;
}
int p[Maxn];
void _init(){
	for (int i=0;i<Maxn;i++) p[i]=i;
}
int findset(int x){
	return p[x]=(p[x]==x)?x:findset(p[x]);
} 
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	p[x]=y;
}
int main(){
	_init();
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d %d",&x[i].first.first,&x[i].first.second);
		x[i].second=i+1;
	}
	sort(x,x+n,cmp1);
	for (int i=0;i<n-1;i++){
		e.push_back(mp(abs(x[i].first.first-x[i+1].first.first),mp(x[i].second,x[i+1].second)));
	}
	sort(x,x+n,cmp);
	for (int i=0;i<n-1;i++){
		e.push_back(mp(abs(x[i].first.second-x[i+1].first.second),mp(x[i].second,x[i+1].second)));
	}
	sort(e.begin(),e.end());
	int cost=0;
	for (int i=0;i<e.size();i++){
		if (findset(e[i].second.first)!=findset(e[i].second.second)){
			Union(e[i].second.first,e[i].second.second);
			cost+=e[i].first;
		}
	}
	printf("%d\n",cost);
}