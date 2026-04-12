#include<bits/stdc++.h>
using namespace std ;

int main () {
	int H , W ;
	cin >> H >> W ;
    char board[H][W] ;
	for(int i = 0 ; i < H ; i++ ){
		for(int j = 0 ; j < W ; j++ ){
			cin >> board[i][j] ;
		}
	}
	int countH[H] = {} , countW[W] = {} ;
	for(int i = 0 ; i < H ; i++ ){
		for(int j = 0 ; j < W ; j++ ){
			if(board[i][j]=='#')countH[i]=1 ;
		}
	}
	for(int i = 0 ; i < W ; i++ ){
		for(int j = 0 ; j < H ; j++ ){
			if(board[j][i]=='#')countW[i]=1 ;
		}
	}
	for(int i = 0 ; i < H ; i++ ){
		for(int j = 0 ; j < W ; j++ ){
			if(countH[i]==1&&countW[j]==1) cout << board[i][j];
		}
		if(countH[i]==1)cout << endl ;
	}
	//for(int i = 0 ; i < H ; i++ ) cout << countH[i] ;
	//for(int i = 0 ; i < W ; i++ ) cout << countW[i] ;
}