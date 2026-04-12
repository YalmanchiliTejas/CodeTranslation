#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<cctype>
#define ld long double
#define ll long long int
#define ull unsigned long long int
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const long long INF=1LL<<60;


int main(void){
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s;
	cin>>s;
	if (s.find("AC")!=string::npos)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	
	return 0;
}