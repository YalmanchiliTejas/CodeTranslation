#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000007
#define LINF 1000000000000000007
 
typedef long long ll;
typedef pair<ll,ll> P;


int h, w;
string a[10];

int main(){
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		cin >> a[i];
	}
	
	bool b = 1;
	if(a[0][0] != '#') b = 0;
	P now = make_pair(0,0);
	while(1){
		a[now.first][now.second] = '.';
		if(now.first < h && a[now.first+1][now.second] == '#'){
			now.first++;
			continue;
		}
		if(now.second < w && a[now.first][now.second+1] == '#'){
			now.second++;
			continue;
		}
		if(now.first != h-1 || now.second != w-1) b = 0;
		break;
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(a[i][j] == '#') b = 0;
		}
	}
	if(b) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	
	return 0;
}