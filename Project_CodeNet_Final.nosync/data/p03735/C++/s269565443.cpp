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
 
const int L=200*1000;
P bs[L];
int N;
int main() {
	cin >> N;
	for(int i=0;i<N;i++){
		int x,y;
		cin >> x >> y;
		if(x>y){
			swap(x,y);
		}
		bs[i]=P(x,y);
	}
	sort(bs,bs+N);
	int r0,r1,b0,b1;
	r0=bs[0].first;
	r1=bs[N-1].first;
	b0=b1=bs[0].second;
	for(int i=1;i<N;i++){
		b0=min(b0,bs[i].second);
		b1=max(b1,bs[i].second);
	}
	LL ret=(r1-r0)*(LL)(b1-b0);
	//cerr << ret << endl;
	r1=b1;
	int m0,m1;
	m0=m1=bs[0].second;
	//cerr << r0 << ", " << r1 << endl;
	for(int i=1;i<N;i++){
		b0=min(bs[i].first,m0);
		b1=max(bs[N-1].first,m1);
		//cerr << b0 << ": " << b1 << endl;
		ret=min(ret,(r1-r0)*(LL)(b1-b0));
		m0=min(m0,bs[i].second);
		m1=max(m1,bs[i].second);
	}
	cout << ret << endl;
	return 0;
}