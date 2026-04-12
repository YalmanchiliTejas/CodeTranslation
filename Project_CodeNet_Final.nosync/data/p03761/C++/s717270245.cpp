#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
 
using namespace std;
 
#define P(p) cout<<(p)<<endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return
#define C(i) cin>>i
#define C2(i,j) cin>>i>>j
#define C3(i,j,k) cin>>i>>j>>k
#define C4(i,j,k,m) cin>>i>>j>>k>>m
////////////////////////////////////////////////////////////

int main(){
	int n;
	cin >> n;
	vector<vector<int>> v;
	rep(i,0,n){
		vector<int> tmp(26,0);
		v.push_back(tmp);
		string s;
		cin >> s;
		rep(j,0,s.size()){
			v[i][s[j]-'a']++;
		}		
	}
	
	string ans = "";
	rep(i,0,26){
		int MIN = 0x7FFFFFFF;
		rep(j,0,n){
			MIN = min(MIN,v[j][i]);
		}
		
		rep(j,0,MIN){
			ans += 'a'+i;
		}
	}
	
	P(ans);
	ret 0;
}