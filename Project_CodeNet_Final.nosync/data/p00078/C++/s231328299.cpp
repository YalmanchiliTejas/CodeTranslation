#include<iostream>
#include<string>
using namespace std;
int main(){
	int dp[20][20];
	int x,y,n;
	while(true){
	    cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=0;
		if(n==0)
			break;
		x=(n-1)/2+1,y=(n-1)/2;
		for(int i=0;i<n*n;i++){
			if(dp[x][y]!=0){
				x++;
				y--;
				if(y<0)
					y+=n;
				x%=n,y%=n;
			}
		    dp[x][y]=i+1;
			x++,y++;
			x%=n,y%=n;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int h=3;
				int k=dp[i][j];
				while(true){
					k/=10;
					if(k==0)
						break;
					h--;
				}
				for(int k=0;k<h;k++)
					cout<<" ";
				cout<<dp[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}