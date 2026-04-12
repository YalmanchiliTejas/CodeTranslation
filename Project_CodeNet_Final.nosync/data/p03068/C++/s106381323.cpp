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
#include<unordered_map>
#include<bitset>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define END {}
#endif
typedef long long ll;
#define int ll
#define uset unordered_set
#define umap unordered_map
typedef std::pair<int,int> P;
struct edge{int to,cost;};
const int INF=100000000000000000;
const int INF2=9223372036854775807;
const int MOD=1000000007;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define min(X,Y) (((int)(X)<(int)(Y))?(X):(Y))
#define max(X,Y) (((int)(X)>(int)(Y))?(X):(Y))
#define MAX(X,Y) (*max_element(X,Y))
#define MIN(X,Y) (*min_element(X,Y))
#define NP(X,Y) next_permutation(X,Y)

int N;
string S;
int K;

signed main(){
	cin>>N>>S>>K;
	char c=S[K-1];
	REP(i,S.size()){
		if(c!=S[i]){
			S[i]='*';
		}
	}
	cout<<S<<endl;
	return 0;
}
