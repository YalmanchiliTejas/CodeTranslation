#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <complex>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second

static const double PI=6*asin(0.5);
typedef pair<double,double> P;
typedef complex<double> CP;
typedef long long ll;


vector <P> a;
char t;
int num[110]={0};
/*
bool operator<(P a,P b){
	return (a.S<b.S);
}
*/
int main(){
	double x,y;
	while(cin>>x>>t>>y,!(x==0&&y==0)){
		P tmp;
		tmp.F=y; tmp.S=x;
		a.PB(tmp);
	}
	sort(ALL(a));
	//rep(i,a.size()) cout<<a[i].F<<" "<<a[i].S<<endl;
	int m=a[a.size()-1].F;
	int co=1;
	rep(i,a.size()){
		if(a[a.size()-1-i].F==m){
			num[a.size()-1-i]=co;
			//cout<<a.size()-1-i<<endl;
		}
		else{
			m=a[a.size()-1-i].F;
			//cout<<m<<endl;
			num[a.size()-1-i]=++co;
		}
	}
	//rep(i,a.size()) cout<<a[i].F<<" "<<a[i].S<<" "<<num[i]<<endl;
	int b;
	while(cin>>b){
		rep(i,a.size()){
			if(a[i].S==b){
				cout<<num[i]<<endl;
				break;
			}
		}
	}
	
	
	return 0;
}
	