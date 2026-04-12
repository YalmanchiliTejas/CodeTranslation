#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;
using ull = unsigned long long;

using namespace std;

const int inf = 1e6 + 7;

int main(){	
	
	int h , w;
	cin >> h >> w;
  char c[h][w];
  for(int i = 0; i < h; i++){
  	for(int j = 0; j < w; j++){
  		cin >> c[i][j];
  	}
  }
  
  for(int i = 1; i < h; i++){
  	for(int j = 1; j < w; j++){
	  	if(c[i][j] == '#'){
	  		if(c[i - 1][j] == '#' && c[i][j - 1] == '#'){
	  			cout << "Impossible" << endl;
	  			return 0;
	  		}
	  	}
  	}
  }
  
   for(int i = 0; i < h - 1; i++){
  	for(int j = 0; j < w - 1; j++){
	  	if(c[i][j] == '#'){
	  		if(c[i + 1][j] == '#' && c[i][j + 1] == '#'){
	  			cout << "Impossible" << endl;
	  			return 0;
	  		}
	  	}
	  }
  }
  
  cout << "Possible" << endl;
	return 0;
}
 