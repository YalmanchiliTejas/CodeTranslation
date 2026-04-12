// 2011/05/25 Tazoe

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	while(true){
		int n;
		cin >> n;
		if(n==0)
			break;

		int mag[15][15];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				mag[i][j] = 0;

		int i = n/2+1;
		int j = n/2;
		mag[i][j] = 1;

		for(int k=2; k<=n*n; k++){
			i++;
			if(i==n)
				i = 0;
			j++;
			if(j==n)
				j = 0;

			if(mag[i][j]==0){
				mag[i][j] = k;
			}
			else{
				while(mag[i][j]!=0){
					i++;
					if(i==n)
						i = 0;
					j--;
					if(j==-1)
						j = n-1;
				}
				mag[i][j] = k;
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				cout << setw(4) << mag[i][j];
			cout << endl;
		}
	}

	return 0;
}