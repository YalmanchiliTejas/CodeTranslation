#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int Max = 1000000;
int main(){
    int H, W;
    cin >> H >> W;
    char A[H][W];

    int cnt = 0;

    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        cin >> A[i][j];
        if(A[i][j]=='#') cnt++;
      }
    }

    if(cnt == H+W-1){
      cout << "Possible" <<endl;
    }else{
      cout << "Impossible" <<endl;
    }

  	return 0;
}
