#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	bool flag =true;
	while(flag){
		priority_queue<pair<int,char> > data;
		while(!data.empty())data.pop();
		for(int i='A';i <='E';i++){
			int x,y;
			cin>>x>>y;
			int sum =x+y;
			if(sum==0){
				flag =false;
				break;
			}
			data.push(mp(sum,i));
		}
		if(flag)
			cout <<data.top().second<<" "<<data.top().first<<endl;
	}
	return 0;
}