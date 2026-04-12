#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


int x[8][2] ={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};


int main()
{
  int n;
    cin >> n;
  int a[200001]={};
  for(int i=0;i<n;i++)
    cin >> a[i];

  if(n%2==0){
    for(int i = n-1;i>=0;i-=2){
      cout << a[i] << " ";
    }
    for(int i=0;i<n;i+=2){
      cout << a[i] << " ";
    }
    cout << endl;
  }
  else{
    for(int i = n-1;i>=0;i-=2){
      cout << a[i] << " ";
    }
    for(int i=1;i<n;i+=2){
      cout << a[i] << " ";
    }
    cout << endl;
  }


  return 0;

}