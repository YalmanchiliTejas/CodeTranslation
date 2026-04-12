#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <stack>
#include <queue>
 
using namespace std;
 
#define pb(n)	push_back(n)
#define mp(n,m) make_pair(n,m)
#define fi 	first
#define se 	second
#define all(r) (r).begin(),(r).end()
 
#define REP(i,s,e)	for(int i=(s); i<(e); i++)
#define rep(i,n)	REP(i,0,n)
#define REPE(i,s,e)	for(int i=s; i>e; i--)
#define repe(i,n)	REPE(i,n,-1)


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<vi> vvi;
 
const int IMAX=((1<<30)-1)*2+1;
const int INF=100000000;
const double EPS=1e-10;
//int mod=1000000007
 

struct Dice{
	int n,e,w,s,d,u;
	Dice(){
		u=1; s=2; e=3; w=4; n=5; d=6;
	}
	void North(){
		int t=u;
		u=s; s=d; d=n; n=t;
	}
	void East(){
		int t=u;
		u=w; w=d; d=e; e=t;
	}
	void West(){
		int t=u;
		u=e; e=d; d=w; w=t;
	}
	void South(){
		int t=u;
		u=n; n=d; d=s; s=t;
	}
	void Right(){
		int t=s;
		s=e; e=n; n=w; w=t;
	}
	void Left(){
		int t=s;
		s=w; w=n; n=e; e=t;
	}
	int Spin(string s){
		if(s=="North") North();
		else if(s=="East") East();
		else if(s=="West") West();
		else if(s=="South") South();
		else if(s=="Right") Right();
		else if(s=="Left") Left();
		return u;
	}
};


int main(){
	int n;
	while(cin>>n && n>0){
		Dice d;
		string s;
		int sum=1;
		rep(i,n){
			cin>>s;
			sum+=d.Spin(s);
		}
		cout<<sum<<endl;
	}
}