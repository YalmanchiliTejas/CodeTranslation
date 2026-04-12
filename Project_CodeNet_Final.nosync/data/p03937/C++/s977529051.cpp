#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;

int main(){
	
	int h, w, s=0;
	string a[8];
	cin >> h >> w;
	for(int i=0; i<h; i++){
		cin >> a[i];
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(a[i][j]=='#'){
				s++;
			}
		}
	}
	if(s==h+w-1){
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}

	return 0;
}
