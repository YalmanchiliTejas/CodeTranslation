#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<utility>
#include<numeric>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<tuple>
#include<stack>
#include<queue>
#include<functional>
#include<iterator>
#include<cmath>
#include<cctype>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = INF+7;

struct edge{int to,cost;};

char a[8][8];
int h,w;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w;

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> a[i][j];
		}
	}
	int i=0,j=0;
	a[0][0]='.';
	while(true){
		if(i==h-1 && j==w-1)  break;
		if(j<w-1 && a[i][j+1]=='#'){
			j++;
			a[i][j]='.';
		}else if(i<h-1 && a[i+1][j]=='#'){
			i++;
			a[i][j]='.';
		}else{
			cout << "Impossible\n";
			return 0;
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(a[i][j]=='#'){
				cout << "Impossible\n";
				return 0;
			}
		}
	}
	cout << "Possible\n";
	
	return 0;
}