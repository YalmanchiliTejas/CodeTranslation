#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
#include <numeric>
#include <math.h>
#define ll long long
#define INF INT_MAX 
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  char a[H][W];
  int ans=0;
  for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
		cin >> a[i][j];
      	if(a[i][j]=='#')ans++;
    }
  }
  if(ans==H+W-1)cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}