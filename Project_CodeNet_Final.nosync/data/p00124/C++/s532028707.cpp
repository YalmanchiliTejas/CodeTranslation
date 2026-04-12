#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

vector<pair<int,string> > country(20);
int n;

void mysort(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(country[j].first<country[j+1].first){
				pair<int,string> buf;
				buf=country[j];
				country[j]=country[j+1];
				country[j+1]=buf;
			}
		}
	}
}

int main() {
	bool f=true;
	while(n=in()){
		if(!f){cout<<endl;}f=false;
		int i;
		int win,lose,draw;
		string str;
		for(i=0;i<n;i++){
			cin>>str>>win>>lose>>draw;
			country[i]=mp(win*3+draw,str);
		}
		mysort();
		for(i=0;i<n;i++){
			cout<<country[i].second<<","<<country[i].first<<endl;
		}
	}
	return 0;
}