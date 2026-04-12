#include <iostream>

using namespace std;
int main()
{
	int H,W,i,j,tmp[110],check[110];
	char a[110][110];
	cin >> H >> W;
	for(i=0; i<H; i++){
		check[i] = 0;
	}
	for(j=0; j<W; j++){
		tmp[j] = 0;
	}
	for(i=0; i<H; i++){
		for(j=0; j<W; j++){
			cin >> a[i][j];
			if(a[i][j] == '#'){
				tmp[j] = 1;
				check[i] = 1;
			}
		}
	}
	/*for(j=0; j<H; j++){
		for(i=0; i<W; i++){
			if(a[i][j] == '#')
				check[i] = 1;
		}
	}*/
	for(i=0; i<H; i++){
		while(i<H){
			if(check[i] == 1)
				break;
			i++;
		}
		for(j=0; j<W; j++){
			while(j < W){
				if(tmp[j] == 1)
					break;
				j++;
			}
			if(j == W || i == H)
				break;
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}
