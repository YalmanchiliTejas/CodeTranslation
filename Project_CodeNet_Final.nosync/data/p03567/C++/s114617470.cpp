#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
string S;
int main(){
	cin>>S;
	bool ans=false;
	REP(i,(int)S.size()-1){
		if(S.substr(i,2)=="AC"){
			ans=true;
		}
	}
	cout<<(ans ? "Yes" : "No")<<endl;
}