#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
//const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
const int dx[8]={-1,0,1,0,-1,-1,1,1},dy[8]={0,-1,0,1,-1,1,-1,1};

const int N=16;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		char c;
		cin>>c;
		if(c=='#') break;
		vector<vs> a(4,vs(13));
		for(int i=0;i<4;i++) for(int j=0;j<13;j++) cin>>a[i][j];
		int p=0,q=0;
		int pre=0;
		for(int i=0;i<13;i++){
			int mx=-1,id=0;
			for(int j=0;j<4;j++){
				int x=0;
				char t=a[j][i][0];
				if(isdigit(t)) x=t-'2';
				if(t=='T') x=9;
				if(t=='J') x=10;
				if(t=='Q') x=11;
				if(t=='K') x=12;
				if(t=='A') x=13;
				t=a[j][i][1];
				if(t==c) x+=10000;
				if(t==a[pre][i][1]) x+=1000;
				if(x>mx){
					mx=x;
					id=j;
				}
			}
			pre=id;
//			cout<<id<<' ';
			if(id%2==1) p++;
			else q++;
		}
//		cout<<endl;
		if(p>q){
			cout<<"EW"<<' '<<p-6<<endl;
		}
		else{
			cout<<"NS"<<' '<<q-6<<endl;
		}
	}
}
