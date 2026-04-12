#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,b,n) for(int i=b;i<n;i++)

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
	int n,m;
	while(cin>>n>>m,n||m){
		vector<int> data;
		data.clear();
		for(int i =0;i <n;i++){
			int x;
			cin>>x;
			data.push_back(x);
		}
		for(int i =0;i<m;i++){
			int x;
			cin>>x;
			data.push_back(x);
		}
		sort(data.begin(),data.end());
		int ans = 0;
		ans =data[0];
		for(int i =0;i <data.size()-1;i++){
			int tmp =data[i+1]-data[i];
			if(tmp>ans){
				ans =tmp;
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}