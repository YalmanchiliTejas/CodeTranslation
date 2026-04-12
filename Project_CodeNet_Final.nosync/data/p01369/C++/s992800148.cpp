#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#define rep(i,l,n) for(lint i=l;i<n;i++)
#define rer(i,l,n) for(lint i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef vector<lint> vli;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){
	string s,t="yuiophjklnm";
	while(1){
		cin>>s;
		string u="";
		if(s=="#") break;
		rep(i,0,s.size()){
			if(t.find(s[i])!=string::npos) u+='1';
			else u+='0';
		}
		int ans=0;
		rep(i,1,u.size()){
			if(u[i]!=u[i-1]) ans++;
		}
		o(ans);
	}
}