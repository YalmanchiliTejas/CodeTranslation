#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include <cmath>
#include <limits>
#include<set>
#include <iomanip>
#include <queue>
#include <string>
#pragma GCC optimize("Ofast")
using namespace std;
const long long INF=20000000000;
//setprecision(2) <<

const int MOD = 1000000007;

long long max(long long a,long long b){
	if(a<b)return b;
	else return a;	
}
long long min(long long a,long long b){
	if(a>b)return b;
	else return a;	
}
long long gcd(long long a,long long b){
	if(a<b)swap(a,b);
	if(a%b==0)return b;
	else return gcd(a%b,b);
}

long long lcm(long long a,long long b){
	return a*b/gcd(a,b);
}

long long com(long long n,long long k){
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>s;
	bool ans=false;
	for(int i=1;i<s.length();i++){
		if(s[i-1]=='A' && s[i] == 'C')ans=true;
	}
	if(ans)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

	
