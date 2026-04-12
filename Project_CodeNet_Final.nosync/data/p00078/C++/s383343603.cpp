#include<iostream>

using namespace std;

int cell[16][16];
int n;

void init()
{
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cell[x][y]=-1;
		}
	}
}

void solve()
{
	init();
	int x,y;
	x=(n-1)/2;
	y=x+1;
	cell[x][y]=1;
	for(int i=2;i<=n*n;i++){
		x++;
		y++;
		if(x>=n){
			x=0;
		}
		if(y>=n){
			y=0;
		}
		if(cell[x][y]!=-1){
			x--;
			y++;
			if(y>=n){
				y=0;
			}
			if(x<0){
				x=n-1;
			}
		}
		cell[x][y]=i;
	}
}

void draw()
{
	for(int y=0;y<n;y++){
		for(int x=0;x<n;x++){
			cout.width(4);
			cout<<cell[x][y];
		}
		cout<<endl;
	}
}

int main(void)
{
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		solve();
		draw();
	}
	return 0;
}