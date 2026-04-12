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
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-11;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

const int n=10;
int a[n][n];

bool f(string s){
	int x=0;
	for(int i=0;i<5;i++) x=a[x][s[i]-'0'];
	return x==0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		string s;
		int x;
		cin>>s>>x;
		int n=s.size(),t=s[0]-'0';
		for(int i=1;i<n;i+=2){
			if(s[i]=='+') t+=s[i+1]-'0';
			else t*=s[i+1]-'0';
		}
		bool b1=0,b2=0;
		if(x==t) b1=1;
		t=0;
		s+='+';
		int tmp=1;
		for(int i=0;i<=n;i+=2){
			if(s[i+1]=='+'){
				tmp*=s[i]-'0';
				t+=tmp;
				tmp=1;
			}
			else{
				tmp*=s[i]-'0';
			}
		}
		if(x==t) b2=1;
		if(b1&&b2) cout<<'U'<<endl;
		if(b1&&!b2) cout<<'L'<<endl;
		if(!b1&&b2) cout<<'M'<<endl;
		if(!b1&&!b2) cout<<'I'<<endl;
		break;
	}
}
