#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		char field[10][10];
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 10; k++)
				cin>>field[j][k];


		// ツ催渉可づ可暗ェツ氾板湘」ツづ個づ青づつュツづィツつゥツつヲツつオツ陛サツづーツ個按津ィ
		for(int s = 0; s < (1 << 10); s++){
			char ret[10][10];
			char sit[10][10];
			for(int j = 0; j < 10; j++){
				for(int k = 0; k < 10; k++){
					sit[j][k]=field[j][k];
				}
			}
			for(int j = 0; j < 10; j++){
				if((s>>j)&1){
					ret[0][j]='1';
					sit[0][j]=((sit[0][j]-'0')^1)+'0';
					if(j-1>=0){
						sit[0][j-1]=((sit[0][j-1]-'0')^1)+'0';
					}
					if(j+1<10){
						sit[0][j+1]=((sit[0][j+1]-'0')^1)+'0';
					}
					sit[1][j]=((sit[1][j]-'0')^1)+'0';
				}
				else{
					ret[0][j]='0';
				}
			}
			// ツ湘」ツづ恵itツづーツ個ゥツづ、ツづ青づつュツづィツ陛板つキツつゥツづつ、ツつゥツづーツ考ツつヲツづゥ
			for(int j = 1; j < 10; j++){
				for(int k = 0; k < 10; k++){
					// ツづ青づつュツづィツつゥツつヲツつキ
					if(sit[j-1][k]=='1'){
						ret[j][k]='1';
						sit[j][k]=((sit[j][k]-'0')^1)+'0';
						if(j-1>=0){
							sit[j-1][k]=((sit[j-1][k]-'0')^1)+'0';
						}
						if(j+1<10){
							sit[j+1][k]=((sit[j+1][k]-'0')^1)+'0';
						}
						if(k-1>=0){
							sit[j][k-1]=((sit[j][k-1]-'0')^1)+'0';
						}
						if(k+1<10){
							sit[j][k+1]=((sit[j][k+1]-'0')^1)+'0';
						}
					}
					else{
						ret[j][k]='0';
					}
				}
			}
			bool ff=false;
			for(int j = 0; j < 10; j++){
				for(int k = 0; k < 10; k++){
					if(sit[j][k]=='1'){
						ff=true;
						break;
					}
				}
				if(ff)
					break;
			}
			if(!ff){
				for(int j = 0; j < 10; j++){
					for(int k = 0; k < 10; k++){
						cout<<ret[j][k];
						if(k==9)
							cout<<endl;
						else
							cout<<" ";
					}
				}
				break;
			}
		}
	}

	return 0;
}