#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdexcept>
#include<stdio.h>
using namespace std;

int main(){
  int n;  cin >> n;
  int h[n]; int ans=0;
  for(int i=0;i<n;i++) cin >> h[i];
  
  for(int p=0;p<n;p++){
    bool pop = true;
    for(int i=0;i<p;i++){
      if(h[p] < h[i]){
        pop = false;
        break;
      }
    }
    if(pop){
      ans++;
    }
  }
  cout << ans <<endl;
}