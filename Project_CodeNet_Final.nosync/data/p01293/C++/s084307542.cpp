#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EPS 1e-9
#define INF MOD
#define MOD 1000000007LL
#define fir first
#define iss istringstream
#define sst stringstream
#define ite iterator
#define ll long long
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define sec second
#define sh(i) (1LL<<i)
#define sz size()
#define vi vector<int>
#define vc vector
#define vl vector<ll>
#define vs vector<string>

char t,l;
string c[5][14];

int p(string a){
	int x=0;
	if(a[1]==t)x+=50;
	if(a[1]==l)x+=20;
	if(isdigit(a[0]))return x+a[0]-'0';
	if(a[0]=='T')return x+10;
	if(a[0]=='J')return x+11;
	if(a[0]=='Q')return x+12;
	if(a[0]=='K')return x+13;
	return x+14;
}

int main(){
	while(cin>>t&&t!='#'){
		rep(i,4)rep(j,13)cin>>c[i][j];
		int w=0,ns=0,ew=0;
		rep(i,13){
			l=c[w][i][1];
			int M=0,m;
			rep(j,4)if(p(c[j][i])>M)M=p(c[j][i]),m=j;
			m%2?ew++:ns++;
			w=m;
		}
		if(ns>ew)cout<<"NS "<<ns-6<<endl;
		else cout<<"EW "<<ew-6<<endl;
	}
}