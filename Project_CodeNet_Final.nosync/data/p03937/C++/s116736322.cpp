#include <iostream>
#include <string>
using namespace std;

int main(){
	int h,w,flag=0;
	cin>>h>>w;
	char map[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>map[i][j];
		}
	}
	int i=0;
	int j=0;
	for(;;){
		if(i==h-1&&j==w-1)break;
			if(map[i+1][j]=='#'&&map[i][j+1]=='#'){
				cout<<"Impossible"<<endl;
				return 0;
			}else if(map[i+1][j]=='#'){
				map[i+1][j]='.';
				//cout<<i<<" "<<j<<endl;
				i=i+1;
			}else if(map[i][j+1]=='#'){
				map[i][j+1]='.';
				//cout<<i<<" "<<j<<endl;
				j=j+1;
			}
		}
		map[0][0]='.';
		
		for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(map[i][j]=='#'){
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
	}
	cout<<"Possible"<<endl;
	return 0;
}