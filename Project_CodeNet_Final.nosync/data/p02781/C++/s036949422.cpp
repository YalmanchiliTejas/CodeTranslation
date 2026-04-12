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

llong f(string s,int k){
	if(s.size()<k) return 0;//前提.
	
	llong res=0;
	
	if(k==1){//再帰の終了条件.
		res+=9*(s.size()-1);
		res+=s[0]-'0';
		return res;
	}
	
	res+=nCk(s.size()-1,k)*pow(9,k);//sの桁未満の場合の数.
	res+=(s[0]-'0'-1)*(nCk(s.size()-1,k-1)*pow(9,k-1));//最大の位が選ばれた場合(ただし,最大値は考慮しない).
	
	int p;
	for(p=1;p<s.size();++p){
		if(s[p]=='0'){}
		else break;
	}
	string t=s.substr(p,s.size()-p);
	res+=f(t,k-1);//最大の位の最大値の場合.
	
	return res;
}

int main(){
	string s;
	int k;
	cin>>s>>k;
	
	cout<<f(s,k)<<endl;
}