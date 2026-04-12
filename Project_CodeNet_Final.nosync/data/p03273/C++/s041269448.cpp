#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<bitset>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long int ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
#define REP(i,n) for(int i=0;i<(n);i++)
const int INF=100000000;

int main(){
	int n,m;
	char s[110][110];
	string t[110];
	vector<string> v;
	vector<string> v2;
	cin>>n>>m;
	REP(i,n){
		cin>>s[i];
	}
	REP(i,n){
		int count=0;
		for(int j=0;j<m;j++){
			if(s[i][j]=='.'){
				count++;
			}
		}
		if(count!=m){
			string tmp;
			REP(j,m)tmp.push_back(s[i][j]);
			v.push_back(tmp);
		}
	}
	n=v.size();
	DEB(v.size())END
	for(int i=0;i<m;i++){
		int count=0;
		for(int j=0;j<n;j++){
			if(v[j][i]=='.'){
				count++;
			}
		}
		if(count!=n){
			string tmp;
			REP(j,n)tmp.push_back(v[j][i]);
			v2.push_back(tmp);
		}
	}
	REP(i,v.size()){
		REP(j,v2.size()){
			cout<<v2[j][i];
		}
		cout<<endl;
	}
	return 0;
}