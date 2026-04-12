#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	multimap<int,string,greater<int> > data;
	bool ok = false;
	while(1){
		data.clear();
		int n;
		cin >> n;
		if(n==0) break;
		string tmp;
		int a,b,c;
		if(ok) cout << endl; 
		if(ok==false) ok = true;
		REP(i,n){
			cin >> tmp >> a >> b >> c;
			data.insert(multimap<int,string>::value_type(a*3+c,tmp));
		}
		for(multimap<int,string>::iterator it = data.begin();it != data.end(); it++){
			cout<<(*it).second<<","<<(*it).first<<endl;
		}
		
	}
	return 0;
}