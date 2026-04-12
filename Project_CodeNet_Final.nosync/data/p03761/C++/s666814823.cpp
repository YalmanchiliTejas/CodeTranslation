#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include <cmath>
#include <limits>
#include<set>
#include <iomanip>
#include <queue>
#include <map>
#include <string>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const long long INF=200000000000000;
const double inf=pow(10,10);
double pi=3.141592653589793;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const ll MOD = 1000000007;
void init(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<fixed;
}

ll getdigit(ll n){
	string s=to_string(n);
	return s.size();
}
	
int main(){
	init();
	vector<ll>num(27,INF);
	ll n;cin>>n;
	for(int i=0;i<n;i++){
		vector<ll>_v(27,0);
		string s;
		cin>>s;
		for(int j=0;j<s.length();j++){
			_v[(s[j]-'a')]++;
		}
		for(int j=0;j<27;j++){
			num[j]=min(_v[j],num[j]);
		}
	}
	string ans;
	for(int i=0;i<27;i++){
		for(int j=0;j<num[i];j++){
			ans+=(char)('a'+i);
		}
	}
	cout<<ans<<endl;
}
