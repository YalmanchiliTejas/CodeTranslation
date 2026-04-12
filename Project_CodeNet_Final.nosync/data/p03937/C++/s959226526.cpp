#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<25;
const ll INF=1ll<<50;
const double pi=acos(-1);
const double eps=1e-8;
const vi emp;

int h,w;
vvc a;

int main(){
	cin>>h>>w;
	a=vvc(h,vc(w));
	for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin>>a[i][j];
	int x=0,y=0;
	if(a[x][y]=='#') a[0][0]='.';
	else{
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i=2;i<h+w;i++){
		if(x+1<h&&a[x+1][y]=='#'){
			a[x+1][y]='.';
			x++;
		}
		else if(y+1<w&&a[x][y+1]=='#'){
			a[x][y+1]='.';
			y++;
		}
		else{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	for(int i=0;i<h;i++) for(int j=0;j<w;j++){
		if(a[i][j]=='#'){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
/*	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++) cout<<a[i][j];
		cout<<endl;
	}*/
	cout<<"Possible"<<endl;
}