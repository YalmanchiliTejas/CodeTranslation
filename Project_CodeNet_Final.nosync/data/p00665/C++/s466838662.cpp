#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iterator>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

typedef pair<int,string> pis;

bool cmp(const pii& a,const pii& b)
{
	return a.first==b.first?a.second<b.second:a.first>b.first;
}

bool ok(vector<pii>& favs,vector<pii>& oths,int k,int l,int num)
{
	if(oths.size()<=k-num)
		return true;
	
	ll need=0;
	rep(i,num){
		if(favs[i].first>oths[k-num].first)
			continue;
		else{
			int diff=oths[k-num].first-favs[i].first;
			bool after=favs[i].second>oths[k-num].second;
			need+=diff+after;
		}
	}
	return need<=l;
}

void solve(vs& names,vi& votes,vs& fnames,int k,int l)
{
	int n=names.size(),m=fnames.size();
	
	vector<pii> favs,oths; // vote,id
	{
		map<string,int> ma;
		rep(i,n)
			ma[names[i]]=0;
		{int i=0; foreach(it,ma)
			it->second=i++;
		}
		vi isfav(n);
		rep(i,m)
			isfav[ma[fnames[i]]]=1;
		rep(i,n){
			vector<pii>& chrs=isfav[ma[names[i]]]?favs:oths;
			chrs.push_back(mp(votes[i],ma[names[i]]));
		}
	}
	
	sort(allof(favs),cmp);
	sort(allof(oths),cmp);
	
	int left=0,right=1+min(m,k);
	while(right-left>1){
		int mid=(left+right)/2;
		if(ok(favs,oths,k,l,mid))
			left=mid;
		else
			right=mid;
	}
	
	cout<<left<<endl;
}

int main()
{
	for(int n,m,k,l;scanf("%d%d%d%d",&n,&m,&k,&l),n|m|k|l;){
		vs names(n);
		vi votes(n);
		for(int i=0;i<n;i++){
			char tmp[11];
			scanf("%s%d",tmp,&votes[i]);
			names[i]=tmp;
		}
		vs favs(m);
		rep(i,m){
			char tmp[11];
			scanf("%s",tmp);
			favs[i]=tmp;
		}
		solve(names,votes,favs,k,l);
	}
	
	return 0;
}