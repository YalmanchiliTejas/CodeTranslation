#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >>h >>w;
  char a[h][w];
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
    	cin >>a[i][j];
    }
  }
  bool boolh[h],boolw[w];
  for (int i=0;i<h;i++){
    boolh[i]=false;
    for (int j=0;j<w;j++){
    	if(a[i][j]=='#')boolh[i]=true;
    }
  }
  for (int j=0;j<w;j++){
    boolw[j]=false;
    for (int i=0;i<h;i++){
    	if(a[i][j]=='#')boolw[j]=true;
    }
  }
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
    	if(boolh[i] && boolw[j])cout <<a[i][j];
    }
    if (boolh[i])cout <<endl;
  }
}