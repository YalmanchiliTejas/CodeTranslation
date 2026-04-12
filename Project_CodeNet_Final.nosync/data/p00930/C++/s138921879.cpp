#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <complex>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
const int p2=1<<19;
int N,Q;
string s;
int segm[p2*2],sega[p2*2],inf=1e8;
set<int> st;
void add(int a,int b,int l,int r,int k,int x){
	if(b<=l||r<=a) return;
	if(a<=l&&r<=b){
		sega[k]+=x;
		return;
	}
	add(a,b,l,(l+r)/2,k*2+1,x);
	add(a,b,(l+r)/2,r,k*2+2,x);
	segm[k]=min(segm[k*2+1]+sega[k*2+1],segm[k*2+2]+sega[k*2+2]);
}
void change(int x){
	if(s[x]=='('){
		s[x]=')';
		st.insert(x);
		add(x,p2,0,p2,0,-2);
	}else{
		s[x]='(';
		st.erase(x);
		add(x,p2,0,p2,0,2);
	}
}
int getmin(int a,int b,int l,int r,int k){
	if(b<=l||r<=a) return inf;
	if(a<=l&&r<=b) return segm[k]+sega[k];
	return min(getmin(a,b,l,(l+r)/2,k*2+1),getmin(a,b,(l+r)/2,r,2*k+2))+sega[k];
}
int main(){
	cin>>N>>Q;
	cin>>s;
	rep(i,N) if(s[i]==')') st.insert(i);
	rep(i,p2) segm[p2-1+i]=inf;
	rep(i,N) segm[p2-1+i]=segm[p2-2+i]+(s[i]=='('?1:-1);
	for(int i=p2-2;i>=0;i--){
		segm[i]=min(segm[i*2+1],segm[i*2+2]);
	}
	rep(i,Q){
		int q;
		cin>>q;
		q--;
		if(s[q]=='('){
			change(q);
			int a=*st.begin();
			cout<<a+1<<endl;
			change(a);
		}else{
			change(q);
			int ub=q,lb=-1;
			while(ub-lb>1){
				int m=(ub+lb)/2;
				if(getmin(m,q+1,0,p2,0)>=2) ub=m;
				else lb=m;
			}
			cout<<ub+1<<endl;
			change(ub);
		}
	}
}