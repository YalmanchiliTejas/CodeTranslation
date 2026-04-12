#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int h,w;
	cin >> h >> w;
	char field[10][10];
	rep(i,h){
		rep(j,w){
			cin >> field[i][j];
		}
	}
	int count = 0;
	rep(i,h){
		rep(j,w){
			if(field[i][j] == '#') count++;
		}
	}
	if(count == w+h-1){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}
    return 0;
}

