#include <bits/stdc++.h>
using namespace std;

int n,m;
int f[20][20];
int tmp[20][20];
void copy(){
	for(int i=0;i<400;i++)tmp[i/20][i%20]=f[i/20][i%20];
}

void rot(int r,int c,int s,int t){
	if(t==90)t=1;
	if(t==180)t=2;
	if(t==270)t=3;
	if(t==360)t=4;
	while(t--){
		copy();
		for(int y=r,X=c;y<=r+s-1;y++,X++){
			for(int x=c,Y=r+s-1;x<=c+s-1;x++,Y--){
				f[x][y]=tmp[X][Y];
			}
		}
	}
}

void rev(int r,int c,int s){
	for(int y=r;y<=r+s-1;y++){
		for(int x=c;x<=c+s-1;x++){
			f[x][y]^=1;
		}
	}
}

void lsft(int r){
	int t=f[1][r];
	for(int x=1;x<n;x++)f[x][r]=f[x+1][r];
	f[n][r]=t;
}

void rsft(int r){
	int t=f[n][r];
	for(int x=n;x>1;x--)f[x][r]=f[x-1][r];
	f[1][r]=t;
}

void ilnd(int r,int c){
	int t=f[c][r];
	stack<int>X,Y;
	X.push(c);Y.push(r);
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	while(!X.empty()){
		int x=X.top(),y=Y.top();
		X.pop();Y.pop();
		if(f[x][y]==t){
			f[x][y]^=1;
			for(int i=0;i<4;i++){
				if(f[x+dx[i]][y+dy[i]]==t){
					X.push(x+dx[i]);Y.push(y+dy[i]);
				}
			}
		}
	}
}

int main(){
	
	while(cin>>n>>m){
		for(int i=0;i<400;i++)f[i/20][i%20]=2;
		for(int y=1;y<=n;y++){
			for(int x=1;x<=n;x++){
				cin>>f[x][y];
			}
		}
		while(m--){
			int o;cin>>o;
			int r,c,s,a;
			if(o==0){
				cin>>r>>c>>s>>a;
				rot(r,c,s,a);
			}
			if(o==1){
				cin>>r>>c>>s;
				rev(r,c,s);
			}
			if(o==2){
				cin>>r;
				lsft(r);
			}
			if(o==3){
				cin>>r;
				rsft(r);
			}
			if(o==4){
				cin>>r>>c;
				ilnd(r,c);
			}
		}
		for(int y=1;y<=n;y++){
			for(int x=1;x<=n;x++){
				cout<<f[x][y]<<" \n"[x==n];
			}
		}
	}
	
	return 0;
}
