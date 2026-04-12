#include <iostream>
using namespace std;

int main() {
	int h,w;cin>>h>>w;
	char a[h][w];
	int x[h][w];
	int y[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>a[i][j];
			if(a[i][j]=='#'){
				x[i][j]=1;
				y[i][j]=1;
			}else{
				x[i][j]=0;
				y[i][j]=0;
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=1;j<w;j++){
			x[i][j]+=x[i][j-1];
		}
	}
	for(int j=0;j<w;j++){
		for(int i=1;i<h;i++){
			y[i][j]+=y[i-1][j];
//			cout<<y[i][j];
		}
//		cout<<endl;
	}
	for(int i=0;i<h;i++){
		if(x[i][w-1]){
			for(int j=0;j<w;j++){
				if(y[h-1][j]){
					cout<<a[i][j];
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
