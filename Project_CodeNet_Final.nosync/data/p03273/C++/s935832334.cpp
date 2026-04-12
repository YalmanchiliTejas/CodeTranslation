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
#include<typeinfo>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef set<int> S;
#define rep(i, n) for(int i=0; i<n; i++)
const ll MOD=1e9+7;

int main(){

	int h, w;
	char a[100][100];
	char d[100][100];
	cin >> h >> w;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> a[i][j];
		}
	}
	bool flag=true;
	bool b[100], c[100];
	for(int i=0; i<100; i++){
		b[i]=true, c[i]=true;
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(a[i][j]=='#'){
				flag=false;
			}
		}
		if(!flag){
			b[i]=false;
		}
		flag=true;
	}
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			if(a[j][i]=='#'){
				flag=false;
			}
		}
		if(!flag){
			c[i]=false;
		}
		flag=true;
	}
	for(int i=0; i<h; i++){
		if(b[i]){
			continue;
		}
		for(int j=0; j<w; j++){
			if(!b[i] && !c[j]){
				cout << a[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}