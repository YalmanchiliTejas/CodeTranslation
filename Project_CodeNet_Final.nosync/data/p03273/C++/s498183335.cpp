#include<iostream>
#include<string>
#include<algorithm>
#include <stdio.h>
using namespace std;
int main() {
  int H,W;
  cin >>H>>W;
  char a[110][110];
  for(int i=0;i<H;i++)
  for(int j=0; j<W;j++)
  cin >> a[i][j];

  int index1[110]={0};
  int index2[110]={0};
  for(int i=0;i<H;i++){
    int count=0;
  for(int j=0; j<W;j++){
  if(a[i][j]=='.') count++;
  }
  if(count==W) index1[i]++;
  }


  for(int i=0;i<W;i++){
    int count=0;
  for(int j=0; j<H;j++){
  if(a[j][i]=='.') count++;
  }
  if(count==H) index2[i]++;
  }

  for(int i=0;i<H;i++){
  for(int j=0; j<W;j++){
    if(index1[i]==0 && index2[j]==0) cout <<a[i][j];
  }
  if(index1[i]==0)
  cout <<endl;
}

}
