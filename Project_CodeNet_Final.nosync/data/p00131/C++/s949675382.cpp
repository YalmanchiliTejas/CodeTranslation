#include <iostream>
#include <algorithm>
using namespace std;

int dx[5]={0,1,0,-1,0};
int dy[5]={1,0,-1,0,0};

typedef struct{
	int m[12][12];
	int l[12][12];
}state;

state push(state t,int x,int y){
	t.l[x][y]=(t.l[x][y]+1)%2;
	for(int i=0;i<5;i++){
		t.m[x+dx[i]][y+dy[i]]=(t.m[x+dx[i]][y+dy[i]]+1)%2;
	}
	return t;
}

int cal(state t,int b){
	for(int i=1;i<=10;i++){
		if(b%2)t=push(t,i,1);
		b/=2;
	}
	for(int i=2;i<=10;i++){
		for(int j=1;j<=10;j++){
			if(t.m[j][i-1]){
				t=push(t,j,i);
			}
		}
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			if(t.m[j][i]){
				return 0;
			}
		}
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			cout<<t.l[j][i];
			if(j==10){
				cout<<endl;
			}
			else cout<<" ";
		}
	}
	
	return 1;
}

int main(){
	int n;cin>>n;
	while(n--){
		state tmp;
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++){
				cin>>tmp.m[j][i];
				tmp.l[j][i]=0;
			}
		}
		for(int i=0;i<=1023;i++){
			if(cal(tmp,i))break;
		}
	}
	
	return 0;
}
