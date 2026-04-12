#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <assert.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define ALL(s) begin(s),end(s)
#define ITE(c) typeof((c).begin())
#define VIEW(dat) for(auto v : dat){cout<<v<<endl;}
#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back
#define INRANGE(x,s,e) ((s)<=(x) && (x)<(e))
#define MP(a,b) make_pair((a),(b))

using namespace std;

int main(){
	int m, S, s, y, n, t, c;
	double p;
	vector<int> dat;

	//ifstream cin("in.txt");

	cin>>m;
	rep(I,m){
		cin>>S>>y>>n;
		dat.clear();
		dat.reserve(n);
		rep(i,n){
			cin>>t>>p>>c;
			s=S;
			if(t){
				rep(j,y){
					double B=s*p;
					s+=B-c;
				}
				dat.push_back(s);
			}else{
				int r=0;
				rep(j,y){
					double B=s*p;
					s-=c;
					r+=B;
				}
				dat.push_back(s+r);
			}
		}
		sort(ALL(dat));
		cout<<dat[n-1]<<endl;
	}
	return 0;
}