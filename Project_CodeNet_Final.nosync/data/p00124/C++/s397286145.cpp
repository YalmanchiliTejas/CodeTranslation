#include<iostream>
#include<complex>
#include<cstring>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<vector>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<functional>
#include<algorithm>
#define rep(i,k) for(int i=0;i<k;i++)
using namespace std;
struct P{
	int v;
	string r;
};

void swap(P *x,P *y){
	string s=x->r;
	int temp=x->v;
	x->r=y->r;
	x->v=y->v;
	y->r=s;
	y->v=temp;
};
int main(){
	int n,x,y,z,now=0;
	string s;
	while(cin>>n,n){
		P tab[20];
		if(now!=0)
		cout<<endl;
		rep(i,n){
			cin>>tab[i].r>>x>>y>>z;
			tab[i].v=x*3+z;
		}
		rep(i,n-1)
			rep(j,n-1){
				if(tab[j].v<tab[j+1].v)
				swap(&tab[j],&tab[j+1]);
		}
		rep(i,n)
			cout<<tab[i].r<<','<<tab[i].v<<endl;
		now++;
	}
	return 0;
}