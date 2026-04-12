#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int H, W; cin >> H >> W;
	vector<string> mp;
	string P, s; int Wx[110], Ho=0;
	for(int i=0; i<W; ++i){
	    P += '.';
	    Wx[i]=0;
	}
	for(int i=0; i<H; ++i){
	    cin >> s;
	    if(s!=P){
	        mp.push_back(s);
	        ++Ho;
	    }
	}
	for(int i=0; i<Ho; ++i){
	    for(int k=0; k<W; ++k) if(mp[i][k]=='.') ++Wx[k];
	}
	for(int i=0; i<Ho; ++i){
	    for(int k=0; k<W; ++k) if(Wx[k]<Ho) cout << mp[i][k];
	    cout << endl;
	}
	return 0;
}
