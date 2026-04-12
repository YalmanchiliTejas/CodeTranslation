#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	
	int n;
	
	while(cin>>n){
		if(n!=0){
			vector < vector<int> >m(n,vector<int>(n));
			int x=(n+1)/2;
			int y=n/2;
			m[x][y]=1;
			int j=2;
				while(j<=n*n){
						x++;
						y++;
					if(x>n-1)
					x=0;
					if(y<0)
					y=n-1;
					if(y>n-1)
					y=0;
					while(m[x][y]!=0){
						x++;
						y--;
					if(x>n-1)
					x=0;
					if(y<0)
					y=n-1;
					if(y>n-1)
					y=0;
				}
					m[x][y]=j++;
					
		}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++)
				printf("%4d",m[i][j]);
				cout<<endl;
			}
	}
		else
			break;
	}
	
}