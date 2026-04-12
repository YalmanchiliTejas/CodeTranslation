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
	int n,num[100][100],min=INF;
	REP(i,100)REP(j,100){
		num[i][j]=0;
	}
	cin>>n;
	REP(i,n){
		string s;
		cin>>s;
		REP(j,s.size()){
			num[i][s[j]-'a']++;
		}
	}
	for(int i=0;i<100;i++){
		min=INF;
		for(int j=0;j<n;j++){
			if(min>num[j][i]){
				min=num[j][i];
			}
		}
		if(min!=0){
			for(int j=0;j<min;j++){
				putchar(i+'a');
			}
		}
	}
	cout<<endl;
	return 0;
}