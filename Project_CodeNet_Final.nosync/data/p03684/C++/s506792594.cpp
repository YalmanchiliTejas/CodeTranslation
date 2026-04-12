#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;
typedef array<int,3> A;

const int L=1e5;
int rep[L];
int Find(int a){
	while(a!=rep[a]){
		a=rep[a]=rep[rep[a]];
	}
	return a;
}
void Union(int a,int b){
	a=Find(a);
	b=Find(b);
	rep[a]=b;
}
int x[L];
int y[L];
P X[L];
P Y[L];
int main() {
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",x+i,y+i);
		X[i]=P(x[i],i);
		Y[i]=P(y[i],i);
		rep[i]=i;
	}
	sort(X,X+N);
	sort(Y,Y+N);
	vector<A> ps;
	for(int i=1;i<N;i++){
		ps.push_back(A{{X[i].first-X[i-1].first,X[i].second,X[i-1].second}});
		ps.push_back(A{{Y[i].first-Y[i-1].first,Y[i].second,Y[i-1].second}});
	}
	sort(ps.begin(),ps.end());
	LL ret=0;
	for(auto a:ps){
		if(Find(a[1])!=Find(a[2])){
			ret+=a[0];
			Union(a[1],a[2]);
		}
	}
	printf("%lld\n",ret);
	

	return 0;
}

