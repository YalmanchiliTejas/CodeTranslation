#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum, cnt;

int main(){
	int h,w;
	cin>>h>>w;
	char c[h][w];
	for(ll i=0; i<h; i++){
		for(ll j=0; j<w; j++){
			cin>>c[i][j];
		}
	}
	for(ll i=0; i<h; i++){
		for(ll j=0; j<w; j++){
			if(c[i][j]=='.' || c[i][j]=='F'){
				bool ok=true;
				for(ll k=0; k<w; k++){
					if(c[i][k]=='#'){
						ok=false;
						break;
					}
				}
				if(ok==true){
					for(ll k=0; k<w; k++){
						c[i][k]='F';
					}
				}
				bool ok2=true;
				for(ll k=0; k<h; k++){
					if(c[k][j]=='#') {
						ok2=false;
						break;
					}
				}
				if(ok2==true){
					for(ll k=0; k<h; k++){
						c[k][j]='F';
					}
				}
			}
		}
	}
	for(ll i=0; i<h; i++){
		bool ok=true;
		for(ll j=0; j<w; j++){
			if(c[i][j]!='F'){
				cout<<c[i][j];
				ok=false;
			}
		}
		if(ok==false) cout<<endl;
	}
}
