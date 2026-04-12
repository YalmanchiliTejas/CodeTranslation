#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main(){
	int H, W;
	cin >> H >> W;
	int i, j;
	int count = 0;
	for (i = 0; i < H; i++){
		string a;
		cin >> a;
		for (j = 0; j < W; j++){
			if (a[j] == '#'){
				count++;
			}
		}
	}
	if (count == H + W - 1){
		cout << "Possible" << endl;
	}
	else{
		cout << "Impossible" << endl;
	}
	return 0;
}