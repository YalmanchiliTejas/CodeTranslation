#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define rep(i, n) for(int i = 0;i < n;i++)
#define reprb(i, n) for(int i = n;i >= 0;i--)
#define reps(i, m, n) for(int i = m;i < n;i++)
#define repsb(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
vector<int> a;
vector<int> b;

int main(int argc,char const *argv[]) {
	int n,s,mx=0,mi=0,total=0;
	while(true)
	{
		total=0,mx=0,mi=100000;
		cin>>n;

		if(n==0)	break;
		rep(i,n){
			cin>>s;
			total+=s;
			mx=max(s,mx);
			mi=min(s,mi);
		}
		total=total-mi-mx;
		total=total/(n-2);
		a.pb(total);
	}
	rep(i,a.size()){
		cout<<a[i]<<endl;
	}
	return 0;
}

