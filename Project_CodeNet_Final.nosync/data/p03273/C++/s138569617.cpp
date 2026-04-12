#include<iostream>
#include<vector>
#include<queue>
#include <string>
#include <sstream>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;



int main(){
    long h,w;
    cin  >> h >> w;
    vector< vector<char> > a(h,vector<char>(w,'.'));

    for (int i = 0; i < h; ++i){
      for(int j=0;j<w;j++){
        cin >> a[i][j];
      }
    }

    // vector< vector<bool> > isWhite(h,vector<bool>(w,false));

    vector<bool>  isWhiteRow(h,false);
    vector<bool>  isWhiteCol(w,false);


    for (int i = 0; i < h; ++i){
      bool isAllwhite =true;
      for(int j=0;j<w;j++){
         if (a[i][j] =='#')isAllwhite=false;
      }
      if (isAllwhite)isWhiteRow[i]=true;
    }

    for (int i = 0; i < w; ++i){
      bool isAllwhite =true;
      for(int j=0;j<h;j++){
         if (a[j][i] =='#')isAllwhite=false;
      }
      if (isAllwhite)isWhiteCol[i]=true;
    }

    for (int i = 0; i < h; ++i){
      if (isWhiteRow[i])continue;
      for(int j=0;j<w;j++){
        if (isWhiteCol[j])continue;
        cout << a[i][j];
      }
      cout << endl;
    }



    
    return 0;
}