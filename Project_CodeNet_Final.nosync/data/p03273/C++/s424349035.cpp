#include<bits/stdc++.h>
using namespace std;
struct block{
	int color;
	bool pd=true;
};
block a[110][110];
int h,w;
bool checkhang(int x){
	for(int i=1;i<=w;i++){
		if(a[x][i].color==1){
			return false;
		}
	}
	return true;
}
void delhang(int x){
	for(int i=1;i<=w;i++){
		a[x][i].pd=false;
	}
}
bool checklie(int x){
	for(int i=1;i<=h;i++){
		if(a[i][x].color==1){
			return false;
		}
	}
	return true;
}
void dellie(int x){
	for(int i=1;i<=h;i++){
		a[i][x].pd=false;
	}
}
int main(){
	cin>>h>>w;
	char sr;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>sr;
			if(sr=='.'){
				a[i][j].color=0;
			}	
			else{
				a[i][j].color=1;
			}
		}
	}
	for(int i=1;i<=h;i++){
		if(checkhang(i)){
			delhang(i);
		}
	}
	for(int i=1;i<=w;i++){
		if(checklie(i)){
			dellie(i);
		}
	}
	bool scpd=false;
	for(int i=1;i<=h;i++){
		scpd=false;
		for(int j=1;j<=w;j++){
			if(a[i][j].pd==true){
				scpd=true;
				if(a[i][j].color==0){
					cout<<".";
				}
				else{
					cout<<"#";
				}
			}
		}
		if(scpd==true)
		cout<<endl;
	}
}