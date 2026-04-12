#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	string s;
	vector<vector<char> >in(110);
	int n;
	cin>>n;
	while(cin>>s,s!="quit"){
		if(s=="push"){
			char d;cin>>n>>d;
			in[n].pb(d);
		}else if(s=="pop"){
			cin>>n;
			cout<<in[n][in[n].size()-1]<<endl;
			in[n].pop_back();
		}else{
			int a,b;
			cin>>a>>b;
			char d=in[a][in[a].size()-1];
			in[a].pop_back();
			in[b].pb(d);
		}
	}
}