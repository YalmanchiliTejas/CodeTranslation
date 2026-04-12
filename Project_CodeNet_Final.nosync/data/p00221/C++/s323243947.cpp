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
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
string itos(int a){
	string s="";
	while(a){
		s=(char)(a%10+'0')+s;
		a/=10;
	}
	return s;
}
int main(){
	int n,m;
	while(cin>>n>>m,n+m){
		vector<bool>ha(n,true);
		vector<string>in(m);
		rep(i,m)cin>>in[i];
		int co=0;
		int no=n;
		loop(i,1,m+1){
			if(no==1)break;
			//テヲツュツ」ティツァツ」テ」ツ?ョテァツ卍コティツィツ?
			string s=itos(i);
			if(i%15==0)s="FizzBuzz";
			else if(i%5==0)s="Buzz";
			else if(i%3==0)s="Fizz";
			//ティツェツーテ」ツ?古ィツィツ?」ツ??」ツ??
			while(ha[co]==false){co++;if(co==n)co=0;}
			//テァツ卍コティツィツ?」ツ?古、ツクツ催ヲツュツ」ティツァツ」テ」ツ?ェテ」ツつ嘉・ツ、ツアテヲツ?シ
			string a=in[i-1];
			if(a!=s){no--;ha[co]=false;}
			co++;
			if(co==n)co=0;
		}
		vi out;
		rep(i,n)if(ha[i])out.pb(i+1);
		rep(i,out.size()-1)cout<<out[i]<<" ";
		cout<<out[out.size()-1]<<endl;
	}
}