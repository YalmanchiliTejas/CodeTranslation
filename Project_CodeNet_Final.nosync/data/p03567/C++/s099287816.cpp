#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	string S;
	cin>>S;
	
	for(int i=0;i<S.size()-1;i++){
		if(S.substr(i,2)=="AC"){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	
	cout<<"No"<<endl;
	
	return 0;
}