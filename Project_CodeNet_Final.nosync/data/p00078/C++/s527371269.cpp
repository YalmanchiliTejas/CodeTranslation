#include <iostream>
using namespace std;

int d[17][17];
int n;
void cal(int x,int y,int num){
	if(num<=n*n){
		if(1<=x && x<=n && 1<=y && y<=n){
			if(d[x][y]==0){
				d[x][y]=num;
				cal(x+1,y+1,num+1);
			}
			else{
				cal(x-1,y+1,num);
			}
			
		}
		else{
			if(x>n){
				cal(1,y,num);
			}
			else if(x<1){
				cal(n,y,num);
			}
			else{
				cal(x,1,num);
				
			}
		}
	}
}


int main(){
	
	
	while(cin>>n,n){
		for(int i=0;i<17;i++){
			for(int j=0;j<17;j++){
				d[i][j]=0;
			}
		}
		for(int i=0;i<17;i++)d[0][i]=d[i][0]=d[n+1][i]=d[i][n+1]=-1;
		
		
		cal(n/2+1,n/2+2,1);
		
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[j][i]>=0){
					if(d[j][i]<1000)cout<<" ";
					if(d[j][i]<100)cout<<" ";
					if(d[j][i]<10)cout<<" ";
					cout<<d[j][i];
				}
			}
			cout<<endl;
		}
	}
	
	return 0;
}
