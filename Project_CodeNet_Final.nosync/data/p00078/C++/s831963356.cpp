#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
	int i,j,n,now,x[15][15];

	while(cin>>n && n){
		memset(x,0,sizeof(x));

		j = n / 2;
		i = j + 1;
		x[i][j] = 1;

		for(now=2;now<=n*n;now++){
			i++; j++;
			while(1){
				if(n <= j) j = 0;
				if(j < 0) j = n - 1;
				if(n <= i) i = 0;

				if(x[i][j] == 0) break;
				else{
					i++; j--;
				}
			}
			x[i][j] = now;
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%4d",x[i][j]);
			}
			cout<<endl;
		}
	}

	return 0;
}