#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
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
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int h,w;
vs a;

void f(){
	vs c;
	for(int i=0;i<h;i++) if(a[i]!=string(w,'.')) c.push_back(a[i]);
	a=c;
	h=a.size();
	vs b(w,string(h,'a'));
	for(int i=0;i<w;i++) for(int j=0;j<h;j++) b[i][j]=a[j][i];
	a=b;
	swap(h,w);
}

int main(){
	cin>>h>>w;
	a=vs(h);
	for(int i=0;i<h;i++) cin>>a[i];
	f();f();
	for(int i=0;i<h;i++) cout<<a[i]<<endl;
}