#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<iomanip>
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) loop(i,0,n)
using namespace std;
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
int main(){
	string s="11111110000000001111011101";
	string in;
	while(cin>>in,in!="#"){
		int co=0;
		
		rep(i,in.size()-1)co+=(s[in[i]-'a']!=s[in[i+1]-'a']);
		cout<<co<<endl;
	}
}
