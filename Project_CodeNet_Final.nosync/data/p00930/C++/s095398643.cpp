#include <iostream>
#include <fstream>
#include <cassert>
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
#include <complex>
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
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-7;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

template <class T>
class Lazy_Segment_Tree{
	private:
	int n;
	vector<T> date,lazy;
	void Set_Lazy(int k,T x){
		date[k]+=x;
		lazy[k]+=x;
	}
	void Push(int k){
		Set_Lazy(k*2+1,lazy[k]);
		Set_Lazy(k*2+2,lazy[k]);
		lazy[k]=0;
	}
	void Fix(int k){
		date[k]=min(date[k*2+1],date[k*2+2]);
	}
	void Add_func(int a,int b,int k,int l,int r,T x){
		if(r<=a||b<=l) return;
		if(a<=l&&r<=b){
			Set_Lazy(k,x);
			return;
		}
		Push(k);
		int m=(l+r)/2;
		Add_func(a,b,k*2+1,l,m,x);
		Add_func(a,b,k*2+2,m,r,x);
		Fix(k);
	}
	void Update_func(int I,int k,int l,int r,T x){
		if(r<=I||I<l) return;
		if(l==I&&r-l==1){
			date[k]=x;
			lazy[k]=x;
			return;
		}
		Push(k);
		int m=(l+r)/2;
		Update_func(I,k*2+1,l,m,x);
		Update_func(I,k*2+2,m,r,x);
		Fix(k);
	}
	T Query_func(int a,int b,int k,int l,int r){
		if(r<=a||b<=l) return inf;
		if(a<=l&&r<=b) return date[k];
		Push(k);
		int m=(l+r)/2;
		T vl=Query_func(a,b,k*2+1,l,m);
		T vr=Query_func(a,b,k*2+2,m,r);
		return min(vl,vr);
	}
	public:
	Lazy_Segment_Tree(int n_){
		n=1;
		while(n<n_) n*=2;
		date=lazy=vector<T>(2*n-1,inf);
	}
	void Add(int a,int b,T x){
		Add_func(a,b,0,0,n,x);
	}
	void Update(int k,T x){
		Update_func(k,0,0,n,x);
	}
	T Query(int a,int b){
		return Query_func(a,b,0,0,n);
	}
	T Open(int k){
		k+=n-1;
		T res=date[k];
		while(k>0){
			k=(k-1)/2;
			res+=lazy[k];
		}
		return res;
	}
	void Full_Open(){
		for(int i=0;i<2*n-1;i++) cout<<date[i]<<' ';
		cout<<endl;
		for(int i=0;i<2*n-1;i++) cout<<lazy[i]<<' ';
		cout<<endl;
	}
};

int n,q;
string s;

int main(){
	cin>>n>>q>>s;
	Lazy_Segment_Tree<int> lst(n);
	int x=0;
	set<int> s1,s2;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			x++;
			s1.insert(i);
		}
		else{
			x--;
			s2.insert(i);
		}
		lst.Update(i,x);
	}
	for(int i=0;i<q;i++){
		int t;
		cin>>t;
		t--;
		if(s[t]=='('){
			s[t]=')';
			s1.erase(t);
			s2.insert(t);
			auto it=s2.begin();
			s1.insert(*it);
			s2.erase(it);
			lst.Add(*it,t,2);
			s[*it]='(';
			cout<<*it+1<<endl;
		}
		else{
			s[t]='(';
			s2.erase(t);
			s1.insert(t);
			int l=-1,r=t;
			while(r-l>1){
				int m=(l+r)/2;
				if(lst.Query(m,t)>=2) r=m;
				else l=m;
			}
			auto it=s1.lower_bound(r);
			s2.insert(*it);
			s1.erase(it);
			lst.Add(*it,t,-2);
			s[*it]=')';
			cout<<*it+1<<endl;
		}
	}
}