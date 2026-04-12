#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <complex>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<long long,int> P;
static const int INF=1<<24;

int main(){
	string stmp1="qazwsxedcrfvtgb",stmp2="yhnujmikolp";
	int st[30];
	rep(i,stmp1.size()){
		st[stmp1[i]-'a']=1;
	}
	rep(i,stmp2.size()){
		st[stmp2[i]-'a']=0;
	}
	string s;
	while(cin>>s,s[0]!='#'){
		int res=0;
		int ju=st[s[0]-'a'];
		rep(i,s.size()){
			if(ju!=st[s[i]-'a']){
				ju=st[s[i]-'a'];
				res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}