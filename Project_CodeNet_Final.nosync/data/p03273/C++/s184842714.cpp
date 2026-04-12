#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000



int main(){
	
	int H,W;
	cin>>H>>W;
	
	vector<string> S(H);
	for(int i=0;i<H;i++){
		cin>>S[i];
	}
	
	for(int i=H-1;i>=0;i--){
		bool f = true;
		for(int j=0;j<W;j++){
			if(S[i][j]=='#')f=false;
		}
		if(f){
			S.erase(S.begin()+i);
		}
	}
	
	for(int i=W-1;i>=0;i--){
		bool f = true;
		for(int j=0;j<S.size();j++){
			if(S[j][i]=='#')f=false;
		}
		if(f){
			for(int j=0;j<S.size();j++){
				S[j].erase(S[j].begin()+i);
			}
		}
	}
	
	for(int i=0;i<S.size();i++){
		cout<<S[i]<<endl;
	}
	
    return 0;
}
