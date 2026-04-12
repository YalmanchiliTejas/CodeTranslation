#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll h, w;
string buf, a[10];

int main(){
	cin >> h >> w;
	for(ll i = 0; i < h; i++){
		cin >> buf;
		a[i] = buf;
	}
	bool flg = true;
	ll at = 0;
	for(ll i = 0; i < h; i++){
		for(ll j = 0; j < at; j++){if(a[i][j] == '#'){flg = false; break;}}
		if(a[i][at] != '#'){flg = false; break;}
		while(at != w-1 && a[i][at+1] == '#'){at++;}
		for(ll j = at+1; j < w; j++){if(a[i][j] == '#'){flg = false; break;}}
	}
	if(at != w-1){flg = false;}
	
	if(flg){cout << "Possible" << endl;}
	else{cout << "Impossible" << endl;}
	return 0;
}