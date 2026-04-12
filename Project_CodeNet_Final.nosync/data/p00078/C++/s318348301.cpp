#include<iostream>
#define MAX 16

using namespace std;

int main(void){
	while( true ){
		int i,j;
		int n;
		int crrNum = 1;
		int jin[MAX][MAX] = {0,};
		
		cin >> n;
		if( n == 0 ) break;

		/* Indian method */
		i = n/2+1, j = n/2;
		jin[i][j] = crrNum++;
		while(true){
			int tmpi = i, tmpj = j;
			i++;
			j++;
			if( i >= n ) i = 0;
			if( j >= n ) j = 0;

			if( jin[i][j] != 0 ){
				if( i + 1 >= n ) i = 0; else i++;
				if( j - 1 < 0 ) j = n - 1; else j--;
				if( jin[i][j] != 0 ) break;
				else jin[i][j] = crrNum++;
			}else jin[i][j] = crrNum++;	
		}

		//output
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				printf("%4d",jin[i][j]);
			}
			cout << '\n';
		}
	}
	return 0;
}