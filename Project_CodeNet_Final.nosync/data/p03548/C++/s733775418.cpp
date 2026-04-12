#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
#include<set>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define P(p) cout<<(p)<<endl;
#define p(p) cout<<(p)<<" ";
#define pb push_back
#define mp make_pair
#define INF 1<<25

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef long long ll;

int dy[8]={1,1,1,0,0,-1,-1,-1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
struct S{
	int a,b,c;
};
bool asc(const S& left,const S& right){
	return left.c > right.c;
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int X,Y,Z;cin>>X>>Y>>Z;
	for(int i=0;;i++){
		int tmp=0;
		tmp+=i*Y;
		tmp+=(i+1)*Z;
		if(tmp>X){
			cout<<i-1<<endl;
			return 0;
		}
	}
	return 0;
}

