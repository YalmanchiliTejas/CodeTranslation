#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type_a,class Type_b> bool chmax(Type_a &a,const Type_b &b){if(a<b){a=b;return true;}return false;}
template<class Type_a,class Type_b> bool chmin(Type_a &a,const Type_b &b){if(a>b){a=b;return true;}return false;}
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

int main(){
	string s;
	cin>>s;
	
	bool jud=true;
	REP(i,3){
		if(s[0]==s[i]){}
		else jud=false;
	}
	
	cout<<((jud)?"No":"Yes")<<endl;
}