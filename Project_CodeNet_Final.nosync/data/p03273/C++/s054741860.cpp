#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H, vector<char>(W));
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j) cin >> a[i][j];
	queue<int> hight;
	queue<int> width;
	bool flag = true;
	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			if(a[i][j]=='#'){
				flag = false;
				break;
			}
		}
		if(flag) hight.push(i);
		flag = true;
	}
	for(int i=0; i<W; ++i){
		for(int j=0; j<H; ++j){
			if(a[j][i]=='#'){
				flag = false;
				break;
			}
		}
		if(flag) width.push(i);
		flag = true;
	}
	int h, w;
	int count = 0;
	for(int i=0; i<H; ++i){
		if(i==0){
			if(hight.empty()){
				h = H+100;
			}else{
				h = hight.front();
				hight.pop();
				hight.push(h);
			}
		}
	if(i==h){
			h = hight.front();
			hight.pop();
			hight.push(h);
			continue;
		}
		++count;
		for(int j=0; j<W; ++j){
			if(j==0 && count == 1){
				if(width.empty()){
					w = W+100;
				}else{
					w = width.front();
					width.pop();
					width.push(w);
				}
			}
			if(j==w){
				w = width.front();
				width.pop();
				width.push(w);
				continue;
			}
			cout << a[i][j];
		}
	cout << endl;
	}
}
