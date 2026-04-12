#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
char c[10][10];
int h,w;
int num = 0;

int dfs(int i,int j,int r,int cnt){
	if(i == h-1 && j == w-1){
		if(cnt == num-1)return 1;
		else return 0;
	}
	
	if(i >= h || j >=w)return 0;

	//cout << i <<  " " << j <<endl;
	
	int a=0,b=0;
	if(c[i-1][j] == '#')if(r != 1)return 0;
	if(c[i][j-1] == '#')if(r != 0)return 0;
	
	if(c[i+1][j] == '#')a = dfs(i+1,j,1,cnt+1);
	if(c[i][j+1] == '#')b = dfs(i,j+1,0,cnt+1);

	return max(a,b);
}
int main(){
	
	cin >> h >> w;
	
	for(int i =0;i<h;i++){
		for(int j =0;j<w;j++){
			cin >> c[i][j];
			if(c[i][j] == '#')num++;
		}
	}

	int ans = dfs(0,0,99,0);

	if(ans ==0)cout <<"Impossible" << endl;
	else cout << "Possible"<< endl;
	

	return 0;
}