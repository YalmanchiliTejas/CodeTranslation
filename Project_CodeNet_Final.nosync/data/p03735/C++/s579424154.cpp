#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
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
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<50;
const double pi=acos(-1);
const double eps=1e-6;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,-0};
const int DX[8]={-1,-1,-1,0,1,1,1,0},DY[8]={1,0,-1,-1,-1,0,1,1};

ll n;
vpll a;

int main(){
	cin>>n;
	a=vpll(n);
	ll R_max=0,R_min=INF,B_max=0,B_min=INF,im,IM,res;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		a[i]={x,y};
		R_min=min(R_min,x);
		B_max=max(B_max,y);
	}
	for(int i=0;i<n;i++){
		if(a[i].first==R_min) im=i;
		if(a[i].second==B_max) IM=i;
	}
	for(int i=0;i<n;i++){
		R_max=max(R_max,a[i].first);
		B_min=min(B_min,a[i].second);
	}
	res=(R_max-R_min)*(B_max-B_min);
	if(im!=IM&&n==2){
		res=min(res,(B_max-R_min)*abs(R_max-B_min));
	}
	else if(im!=IM){
		R_max=B_max;
		vpll b;
		for(int i=0;i<n;i++) if(i!=im&&i!=IM) b.push_back(a[i]);
		sort(b.begin(),b.end());
		vl bm(n-1),BM(n-1);
		bm[0]=min(a[im].second,a[IM].first);
		BM[0]=max(a[im].second,a[IM].first);
		for(int i=1;i<n-1;i++){
			bm[i]=min(bm[i-1],b[i-1].second);
			BM[i]=max(BM[i-1],b[i-1].second);
		}
		for(int i=0;i<=n-2;i++){
			B_max=max((i==n-2?-1:b[n-3].first),BM[i]);
			B_min=min((i==n-2?INF:b[i].first),bm[i]);
			res=min(res,(R_max-R_min)*(B_max-B_min));
		}
	}
	cout<<res<<endl;
}