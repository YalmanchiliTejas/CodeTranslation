#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main(){
		int W,H;
		cin >> H >> W; cin.ignore();
		char a[H][W];
		bool isRowHasbl[110];
		bool isColHasbl[110];

		string s;
		memset(isColHasbl, false,sizeof(isColHasbl));
		memset(isRowHasbl, false,sizeof(isRowHasbl));
		for(int i=0;i<H;i++){
				getline(cin,s);
				for(int j=0;j<W;j++){
						a[i][j] = s[j];
						if(s[j]== '#'){
							isRowHasbl[i]=true;
							isColHasbl[j]=true;
						}
				}
		}

		for(int i=0;i<H;i++){
				if (isRowHasbl[i]==false)continue;
				for(int j=0;j<W;j++){
						if(isColHasbl[j] == true){
								cout << a[i][j];
						}
				}
				printf("\n");
		}
}



