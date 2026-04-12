#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
int powint(int a, int x){
	int res = 1;
	REP(i,x){
		res = res *a; 
	}
	return res;
}

using namespace std;

int main(){
	string S;
	cin>>S;
	
	if(S.find("AC") != std::string::npos){
		cout<<"Yes"<<endl;		
	} else {
		cout<<"No"<<endl;
	}
	return 0;
}
