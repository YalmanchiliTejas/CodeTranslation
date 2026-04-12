#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<cctype>
#define ld long double
#define ll long long int
#define ull unsigned long long int
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const long long INF=1LL<<60;
//set<int>::iterator it;

int main(void){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int i,j,h,w;
	cin>>h>>w;
	char a[h+1][w+1];
	for(i=1;i<h+1;i++){
		for(j=1;j<w+1;j++){
			cin>>a[i][j];
			if(a[i][j]=='#'){
				a[0][j]='#';
				a[i][0]='#';
			}
		}
	}
	bool aa;
	for(i=1;i<h+1;i++){
		aa=false;
		for(j=1;j<w+1;j++){
			if(a[i][0]=='#'&&a[0][j]=='#'){
				cout<<a[i][j];
				aa=true;
			}
		}
		if(aa)cout<<endl;
	}
	
	
	
	
	
	return 0;
}