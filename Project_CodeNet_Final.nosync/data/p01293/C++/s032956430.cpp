#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <iomanip>
#include <stack>
  
using namespace std;

#define pi 3.141592653589793

int Winner(int t, string c[4][13], int n, char s)
{
	int maxnum = 0;
	bool istheretrump = false;
	int ans;
	for(int i = 0; i < 4; i++){
		int rank;
		if(c[i][n][0] == 'T') rank = 10;
		else if(c[i][n][0] == 'J') rank = 11;
		else if(c[i][n][0] == 'Q') rank = 12;
		else if(c[i][n][0] == 'K') rank = 13;
		else if(c[i][n][0] == 'A') rank = 14;
		else rank = c[i][n][0] - '0';
		if(c[i][n][1] == t){
			if(!istheretrump){
				maxnum = rank;
				ans = i;
				istheretrump = true;
			} else if(rank > maxnum){
				maxnum = rank;
				ans = i;
			}			
		} else if(!istheretrump && c[i][n][1] == s && rank > maxnum){
			maxnum = rank;
			ans = i;
		}
	}
	// cout << ans << endl;
	return ans;
}

int main()
{
	char trump;
	string card[4][13];
	while(1){
		cin >> trump;
		if(trump == '#') break;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 13; j++){
				cin >> card[i][j];
			}
		}
		int score[4] = {};
		char suit = card[0][0][1];
		for(int i = 0; i < 13; i++){
			int w = Winner(trump, card, i, suit);
			score[w]++;
			if(i != 12) suit = card[w][i + 1][1];
		}
		int ns = score[0] + score[2], ew = score[1] + score[3];
		if(ns > ew){
			cout << "NS" << " " << ns - 6 << endl;
		} else {
			cout << "EW" << " " << ew - 6 << endl;
		}
	}
	return 0;
}