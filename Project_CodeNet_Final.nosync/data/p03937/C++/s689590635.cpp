#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int h, w, v[9][9];
char arr[9][9];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>h>>w;
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			cin>>arr[i][j];
		}
	}
	int a=0, b=0;
	if(arr[0][0]!='#'){
		cout<<"Impossible";
		return 0;
	}
	while(a!=h-1||b!=w-1){
		v[a][b]=1;
		if(arr[a+1][b]=='#'&&arr[a][b+1]!='#'){
			a++;
		}else if(arr[a][b+1]=='#'&&arr[a+1][b]!='#'){
			b++;
		}else{
			cout<<"Impossible";
			return 0;
		}
	}
	v[h-1][w-1]=1;
	for (int i = 0; i < h; ++i){
		for (int j = 0; j < w; ++j){
			if(arr[i][j]=='#'&&v[i][j]!=1){
			cout<<"Impossible";
			return 0;
		}
		}
	}
	cout<<"Possible";
	return 0;
}