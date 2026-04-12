#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  while(n--){
    int dtct[10][10];
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 0, 0, 1};
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
	cin >> dtct[i][j];
      }
    }
    
    for(int i = 0; i < 1 << 10; i++){
      int axi[10][10] = {{0}};
      int tmp[10][10] = {{0}};
      for(int j = 0; j < 10; j++){
	axi[0][j] = (i >> j) & 1;
	if(axi[0][j] == 0) continue;
	for(int k = 0; k < 4; k++){
	  int nx = j + dx[k], ny = dy[k];
	  if(nx < 0 || 10 <= nx || ny < 0 || 10 <= ny) continue;
	  tmp[ny][nx]++;
	}
      }
      for(int j = 1; j < 10; j++){
	for(int k = 0; k < 10; k++){
	  if((dtct[j-1][k]+tmp[j-1][k])%2 == 1){
	    axi[j][k] = 1;
	    for(int l = 0; l < 4; l++){
	      int nx = k + dx[l], ny = j + dy[l];
	      if(nx < 0 || 10 <= nx || ny < 0 || 10 <= ny) continue;
	      tmp[ny][nx]++;
	    }
	  }
	}
      }
      bool flag = true;
      for(int j = 0; j < 10; j++){
	if((tmp[9][j]+dtct[9][j])%2 == 1) flag = false;
      }
      if(flag){
	for(int j = 0; j < 10; j++){
	  for(int k = 0; k < 10; k++) cout << axi[j][k] << (k == 9 ? "\n":" ");
	}
	break;
      }
    }
  }
  return 0;
}