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
	
	int j,i,h,w,f,l,lal=-1,lf=-1;
	string s;
	cin>>h>>w;
	for(i=0;i<h;i++){
		f=l=-1;
		cin>>s;
		for(j=0;j<w;j++){
			if(s[j]=='#'){
				f=j;
				break;
			}
		}
		l=f;
		for(j=f;j<w;j++){
			if(s[j]=='#')l=j;
		}
		if(lal==-1){
			lal=l;
			lf=f;
			continue;
		}
		else{
			if(lal!=f){
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
		lal=l;
		lf=f;
	}
	cout<<"Possible"<<endl;
	
	return 0;
}
