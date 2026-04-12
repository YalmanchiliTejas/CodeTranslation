#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
typedef long long int ll;
using namespace std;

int main()
{
	int h,w;
	cin >> h >> w;
	char c;
	int a[h][w];
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> c;
			if(c=='#'){
				a[i][j]=1;
			}else{
				a[i][j]=0;
			}
		}
	}

	int tate,yoko;
	for(int i=0;i<h;i++){
		for(int j=0; j<w; j++){
			tate=0;
			yoko=0;
			for(int k=0; k<w; k++){
				yoko += a[i][k];
			}
			for(int k=0; k<h; k++){
				tate += a[k][j];
			}
			if(tate!=0 && yoko!=0){
				if(a[i][j]==1){
					cout << "#";
				}else{
					cout << ".";
				}
			}
		}
		if(yoko){
			cout << endl;
		}
	}
	return 0;
}