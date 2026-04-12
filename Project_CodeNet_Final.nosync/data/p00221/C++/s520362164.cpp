#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b,a||b){
		vector<bool>me(a,true);
		int k=0;
		int co=0;
		loop(i,1,b+1){
			string s;
			cin>>s;
			bool h=false;
			if(i%15==0){if(s=="FizzBuzz")h=true;}
			else if(i%5==0){if(s=="Buzz")h=true;}
			else if(i%3==0){if(s=="Fizz")h=true;}
			else if(atoi(&s[0])==i)h=true;
			while(1){
				if(!me[k]){k++;if(k==a)k=0;}
				else break;
			}
			if(!h){co++;me[k]=false;}	
			if(co+1==a){rep(q,b-i)cin>>s;break;}
			k++;
			if(k==a)k=0;
		}
		vector<int>out;
		rep(i,a)if(me[i])out.pb(i+1);
		rep(i,out.size()-1)cout<<out[i]<<" ";
		cout<<out[out.size()-1]<<endl;
	}
}