#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=200050;
//ここまでテンプレ
struct SegmentTreeMin {
private:
    int n;
    vector<int> node;

public:
    SegmentTreeMin(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
	void update(int x, int val) {
		x += (n - 1);
		node[x] = val;
		while(x > 0) {
			x = (x - 1) / 2;
			node[x] = min(node[2*x+1], node[2*x+2]);
		}
	}
	int getmin(int a, int b, int k=0, int l=0, int r=-1) {
		if(r < 0) r = n;
		if(r <= a || b <= l) return INF;
		if(a <= l && r <= b) return node[k];
		int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
		int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
		return min(vl, vr);
	}
};
struct SegmentTreeMax {
private:
    int n;
    vector<int> node;

public:
    SegmentTreeMax(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }
	void update(int x, int val) {
		x += (n - 1);
		node[x] = val;
		while(x > 0) {
			x = (x - 1) / 2;
			node[x] = max(node[2*x+1], node[2*x+2]);
		}
	}
	int getmax(int a, int b, int k=0, int l=0, int r=-1) {
		if(r < 0) r = n;
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return node[k];
		int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
		int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
		return max(vl, vr);
	}
};
//↑SegTree
int main(){
	int N;
	cin>>N;
	vint A,B;
	vpint X;
	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		if(y<x)
			swap(x,y);
		X.eb(x,y);
	}
	sort(X.begin(),X.end());
	for(pint P:X){
		int x=P.first,y=P.second;
		A.pb(x);
		B.pb(y);
	}
	SegmentTreeMax Xmax(A),Ymax(B);
	SegmentTreeMin Xmin(A),Ymin(B);
	//最初、minはB,maxはRに入れるとする
	ll Bmin=INF,Bmax=0,Rmin=INF,Rmax=0;
	//初期状態を作る
	for(pint P:X){
		ll x=P.first,y=P.second;
		Bmin=min(Bmin,x);
		Bmax=max(Bmax,x);
		Rmin=min(Rmin,y);
		Rmax=max(Rmax,y);
	}
	ll ans=(Rmax-Rmin)*(Bmax-Bmin);
	for(int i=0;i<N-1;i++){
		Bmin=min(Ymin.getmin(0,i+1),Xmin.getmin(i+1,N));
		Bmax=max(Ymax.getmax(0,i+1),Xmax.getmax(i+1,N));
		Rmin=min(Xmin.getmin(0,i+1),Ymin.getmin(i+1,N));
		Rmax=max(Xmax.getmax(0,i+1),Ymax.getmax(i+1,N));
		ans=min(ans,(Rmax-Rmin)*(Bmax-Bmin));
	}
	cout<<ans<<endl;
	return 0;
}