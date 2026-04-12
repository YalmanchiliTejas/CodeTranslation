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
typedef    pair<int,pair<int,string> >    P;
const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int n;
int main(){
	string team;
	vector<P> data;

	int w,l,d;
	int c =0;
	while(cin>>n,n){
		if(c!=0){
			cout <<endl;
		}
		data.clear();
		for(int i =0;i <n;i++){
			cin>>team>>w>>l>>d;
			int sum =w*3+d*1;
			data.push_back(P(sum,mp(-i,team)));
		}
		sort(data.begin(),data.end(),greater<P>());
		for(int i =0;i <data.size();i++){
			string out =data[i].second.second;
			int score =data[i].first;
			cout <<out<<","<<score<<endl;
		}
		c++;
	}
	return 0;
}