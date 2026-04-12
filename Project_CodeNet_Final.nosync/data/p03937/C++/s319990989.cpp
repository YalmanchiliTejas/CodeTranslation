#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define VSORT(v) sort(v.begin(), v.end())
#define DVSORT(v) sort(v.begin(), v.end(),greater<int>())
#define SORT(v, n) sort(v, v+n)
#define DSORT(v,n) sort(v, v+n,greater<int>())
#define vi vector<int>
#define pb push_back
#define P pair<int,int>
#define Pll pair<ll,ll>

template <class T> void chmin(T&a,const T&b) { a = min(a,b); }
template <class T> void chmax(T&a,const T&b) { a = max(a,b); }
 
void print(){cout<<endl;}
template <class Head, class... Tail>
void print(Head&& h,Tail&&... t){ 
	if(sizeof...(t)==0)
		cout<<h;
	else
		cout<<h<<' ';
	print(move(t)...);
}
 
const double EPS =1e-9;
const int INF =2e+9;
const ll INFL =9e+18;
const long MOD =1e+9+7;
#define PI 3.14159265258979

int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

int H,W;

bool fn(int i,int j,char A[10][10]){
	A[i][j]='.';
	if(i==H&&j==W){
		FOR(i,1,H+1)
			FOR(j,1,W+1)
				if(A[i][j]=='#') 
					return false;

		return true;
	}else{
		bool flug=true;
		if(A[i+1][j]=='#'){
			flug=false;
			return fn(i+1,j,A);
		}
		if(A[i][j+1]=='#'){
			flug=false;
			return fn(i,j+1,A);
		}
		if(flug) return false;
	}
	A[i][j]='#';
}

int main(void){
	char A[10][10];
	cin>>H>>W;
	FOR(i,1,H+1)
		FOR(j,1,W+1)
			cin>>A[i][j];

	if(A[1][1]=='#'&&fn(1,1,A)) print("Possible");
	else print("Impossible");
	return 0;
}
