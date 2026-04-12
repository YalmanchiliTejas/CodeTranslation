#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#include<bitset>
#include<iomanip>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
string ss[400001],tt[400001];
int main(){
	int L;
	string s,t;
	vpint kuminum;
	scan(L);scan(s);scan(t);
	ss[0]="",tt[0]="";
	int sl=s.size(),tl=t.size();
	string ans="";
	rep(i,L){
		ans+='~';
	}
	/*for(int i=1;i*sl<=L&&i<=L;i++){
		ss[i]=ss[i-1]+s;
	}
	for(int i=1;i*tl<=L&&i<=L;i++){
		tt[i]=tt[i-1]+t;
	}*/
	int sl1,sl2,tl1,tl2;
	string kouho1,kouho2;
	for(int i=0;i*sl<=L;i++){
		if((L-i*sl)%tl==0){
			//kuminum.push_back(mp(i,(L-i*sl)/tl));
			//kouho1=tt[(L-i*sl)/tl]+ss[i];
			sl1=i,tl1=(L-i*sl)/tl;
			break;
		}
	}
	for(int i=0;i*tl<=L;i++){
		if((L-i*tl)%sl==0){
			//kuminum.push_back(mp(i,(L-i*sl)/tl));
			//kouho2=ss[(L-i*tl)/sl]+tt[i];
			sl2=(L-i*tl)/sl,tl2=i;
			break;
		}
	}
	if(s+t<t+s){
		rep(i,sl2) printf("%s",s.c_str());
		rep(i,tl2) printf("%s",t.c_str());
	}
	else{
		rep(i,tl1) printf("%s",t.c_str());
		rep(i,sl1) printf("%s",s.c_str());
	}
	kaigyo;
	//ans=min(kouho1,kouho2);
	/*rep(i,kuminum.size()){
		int snum=kuminum[i].first,tnum=kuminum[i].second;
		if(snum*sl+tnum*tl!=L||sl==0||tl==0){
			prin("Oops");
			return 0;
		}
		string kouho;
		if(snum==0){
			kouho=tt[tnum];
		}
		else if(tnum==0){
			kouho=ss[snum];
		}
		else if(ss[snum].substr(0,min(ss[snum].size(),tt[tnum].size()))<tt[tnum].substr(0,min(ss[snum].size(),tt[tnum].size()))){
			kouho=ss[snum]+tt[tnum];
		}
		else{
			kouho=tt[tnum]+ss[snum];
		}
		ans=min(ans,kouho);
	}*/
	//prin(ans);
	return 0;
}
