#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type_a,class Type_b> void chmax(Type_a &a,const Type_b &b){if(a<b)a=b;}
template<class Type_a,class Type_b> void chmin(Type_a &a,const Type_b &b){if(a>b)a=b;}
template<class Type> Type igcd(Type x,Type y){if(x==0||y==0)return (x>y)?x:y;return (y%x)?igcd(y%x,x):x;}
template<class Type> Type ilcm(Type x,Type y){return x/igcd(x,y)*y;}
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

template<class Type,class Type_k>
Type nCk(Type n,Type_k k){//nCk.
	if(n<k) return 0;
	if(n<0 or k<0) return 0;
	Type res=1;
	for(Type i=0;i<k;++i) res*=n-i, res/=i+1;
	return res;
}

llong solve1(string s){
	if(s.size()<1) return 0;
	
	llong res=9*(s.size()-1);
	res+=s[0]-'0';
	
	return res;
}

llong solve2(string s){
	if(s.size()<2) return 0;
	
	llong res=nCk(s.size()-1,2)*pow(9,2);
	res+=(s[0]-'0'-1)*((s.size()-1)*9);
	
	int i;
	for(i=1;i<s.size();++i){
		if(s[i]!='0') break;
	}
	string t=s.substr(i,s.size()-i);
	res+=solve1(t);
	
	return res;
}

llong solve3(string s){
	if(s.size()<3) return 0;
	
	llong res=nCk(s.size()-1,3)*pow(9,3);
	res+=(s[0]-'0'-1)*nCk(s.size()-1,2)*pow(9,2);
	
	int i;
	for(i=1;i<s.size();++i){
		if(s[i]!='0') break;
	}
	string t=s.substr(i,s.size()-i);
	res+=solve2(t);
	
	return res;
}

int main(){
	string s;
	int k;
	cin>>s>>k;
	
	llong ans;
	if(k==1) ans=solve1(s);
	else if(k==2) ans=solve2(s);
	else if(k==3) ans=solve3(s);
	
	cout<<ans<<endl;
}