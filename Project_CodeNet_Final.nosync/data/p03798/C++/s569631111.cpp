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
#include<iomanip>
#include<list>
#include<deque>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define END cout<<endl;
#define DEB2(X) cout<<X<<" ";
#else
#define DEB(X) {}
#define END {}
#define DEB2(X) {}
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
#define setp(X,Y) cout<<fixed<<setprecision(Y)<<X;
int ceil2(int a,int b){if(a%b==0){return a/b;}else{return a/b+1;}}
int pow2(int a,int b){int r=1;for(int i=1;i<=b;i++){r*=a;}return r;}
int Log2(int a){int t=0;while(1){if(a==0||a==1){break;}a/=2;t++;}return t;}

int N;
string S;
int A[100010];
bool F[100010];

void run(int a,int b){
	REP(i,N){
		A[i]=0;
	}
	A[0]=a,A[1]=b;
	for(int i=2;i<N;i++){
		int P=A[i-2];
		int Q=F[i-1];
		if(A[i-1]==1){
			Q=!Q;
		}
		if(P==0&&Q==0){
			A[i]=0;
		}
		else if(P==0&&Q==1){
			A[i]=1;
		}
		else if(P==1&&Q==0){
			A[i]=1;
		}
		else{
			A[i]=0;
		}
	}
}

void solve(int a,int b){
	run(a,b);
	vector<int> v;
	v.push_back(A[N-1]);
	bool flag=true;
	REP(i,N){
		v.push_back(A[i]);
	}
	v.push_back(A[0]);
	for(int i=1;i<=N;i++){
		int p=i-1;
		if(v[i]==0){
			if(F[p]==1&&v[i-1]==v[i+1]){
				flag=false;
			}
			if(F[p]==0&&v[i-1]!=v[i+1]){
				flag=false;
			}
		}
		else{
			if(F[p]==0&&v[i-1]==v[i+1]){
				flag=false;
			}
			if(F[p]==1&&v[i-1]!=v[i+1]){
				flag=false;
			}
		}
	}
	if(flag==true){
		REP(i,N){
			if(A[i]==0){
				cout<<"S";
			}
			else{
				cout<<"W";
			}
		}
		cout<<endl;
		exit(0);
	}
}

signed main(){
	cin>>N>>S;
	REP(i,N){
		if(S[i]=='x')F[i]=1;
	}
	solve(0,0);
	solve(0,1);
	solve(1,0);
	solve(1,1);
	cout<<-1<<endl;
	return 0;
}
