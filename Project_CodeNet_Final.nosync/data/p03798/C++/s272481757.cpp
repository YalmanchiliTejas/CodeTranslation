#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int n;
	string s;
	char c[2]={'S','W'};
	string ans="";
	cin>>n>>s;
	FOR(a1,0,2){
		FOR(a2,0,2){
			ans="";
			ans+=c[a1];
			ans+=c[a2];
			FOR(i,1,n){
				if(ans[i]=='S'){
					if(s[i]=='o'){
						ans+=ans[i-1];
					}else{
						if(ans[i-1]=='S')ans+=c[1];
						else ans+=c[0];
					}
				}else{
					if(s[i]=='o'){
						if(ans[i-1]=='S')ans+=c[1];
						else ans+=c[0]; 
					}else{
						ans+=ans[i-1];
					}
				}
			}
			if(ans[0]==ans[n]){
				if(ans[0]=='S'&&s[0]=='o'){
					if(ans[n-1]!=ans[1])continue;
				}else if(ans[0]=='S'&&s[0]=='x'){
					if(ans[n-1]==ans[1])continue;
				}else if(ans[0]=='W'&&s[0]=='o'){
					if(ans[n-1]==ans[1])continue;
				}else{
					if(ans[n-1]!=ans[1])continue;
				}
				FOR(i,0,n){
					cout<<ans[i];
				}
				cout<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;

    return 0;
}
