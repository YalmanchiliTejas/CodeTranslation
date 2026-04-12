#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
string s;
int solve1(){
	int a=0;
	rep(i,s.size()){
		int t=s[i]-'0';
		while(!(i==s.size()-1||s[i+1]=='+')){
			i+=2;
			t*=s[i]-'0';
		}
		i++;
		a+=t;
	}
	return a;
}
int solve2(){
	int a=s[0]-'0';
	loop(i,1,s.size()){
		if(s[i++]=='+')a+=s[i]-'0';
		else a*=s[i]-'0';
	}
	return a;
}
int main(){
	int a;
	cin>>s>>a;
	bool h1=false,h2=false;
	if(solve1()==a)h1=true;
	if(solve2()==a)h2=true;
	if(h1+h2==2)cout<<"U"<<endl;
	else if(h1)cout<<"M"<<endl;
	else if(h2)cout<<"L"<<endl;
	else cout<<"I"<<endl;
}