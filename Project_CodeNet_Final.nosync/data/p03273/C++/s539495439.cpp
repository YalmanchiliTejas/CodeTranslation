#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;
const int M = 100 + 5;
int main(){
	int a[M][M] = {0},b[M]={0},d[M]={0};
	char c;
	int h,w,x,y;
	cin>>h>>w;
	y=0;
	x=w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>c;
			if(c=='#'){
				a[i][j]=1;
				b[i]=1;
				x=min(x,j);
				y=max(y,j);
			} 
			else
				a[i][j]=0;
		}
	}
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			if(a[j][i]!=0){
				d[i]=1;
				break;
			}
		} 
	}
	for(int i=0;i<h;i++){
		if(b[i]==0)continue;
		for(int j=x;j<=y;j++){
			if(d[j]==0)continue;
			if(a[i][j]==0)
				cout<<'.';
			else
				cout<<'#';
		}
		cout<<endl;
	}
	return 0;
}