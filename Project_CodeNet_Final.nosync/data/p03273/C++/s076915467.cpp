#include<iostream>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	int i, j, B[H][W];;
	char A[H][W];
	for(i=0; i<H; i++){
		for(j=0; j<W; j++){
			cin >> A[i][j];
			if(A[i][j]=='#')	B[i][j] = 1;
			else			B[i][j] = 0;
		}
	}
	
	//行列ごとの計算
	int sumH[H], sumW[W];
	for(i=0; i<H; i++){
		sumH[i]=0;
		for(j=0; j<W; j++){
			sumH[i] += B[i][j];
		}
	}
	for(j=0; j<W; j++){
		sumW[j]=0;
		for(i=0; i<H; i++){
			sumW[j] += B[i][j];
		}
	}
	
	//移動
	int k, countH=0, countW=0;
	for(i=H-1; i>=0; i--){
		if(sumH[i]==0){
			countH++;
			for(j=0; j<W; j++){
				for(k=i; k<H; k++){
					A[k][j] = A[k+1][j];
				}
			}
		}
	}
	H -= countH;

	for(j=W-1; j>=0; j--){
		if(sumW[j]==0){
			countW++;
			for(i=0; i<H; i++){
				for(k=j; k<W; k++){
					A[i][k] = A[i][k+1];
				}
			}
		}
	}
	W -= countW;
	
	for(i=0; i<H; i++){
		for(j=0; j<W; j++){
			cout << A[i][j];
		}
		cout << endl;
	}

	return 0;
}