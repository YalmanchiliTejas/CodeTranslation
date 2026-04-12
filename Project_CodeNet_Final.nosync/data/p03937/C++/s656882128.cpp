#include <bits/stdc++.h>
using namespace std;



int dy[]={0, 1};
int dx[]={1, 0};

int main(){
	int H,W;
	bool ok=true;
	cin >> H >> W;
	int A[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			char ch;
			cin >> ch;
			if(ch=='#') A[i][j]=1;
			else A[i][j]=0;
		}
	}
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			int ny=i+dy[0],nx=j+dx[0];
			int ny2=i+dy[1],nx2=j+dx[1];
			
			if(ny<0 || ny>=H || nx<0 || nx>=W)
				continue;
			if(ny2<0 || ny2>=H || nx2<0 || nx2>=W)
				continue;
			
			if(A[ny][nx]==1&&A[ny2][nx2]==1) ok=false;
		}
	}
	
	cout << (ok?"Possible":"Impossible") << endl;

	return 0;
}