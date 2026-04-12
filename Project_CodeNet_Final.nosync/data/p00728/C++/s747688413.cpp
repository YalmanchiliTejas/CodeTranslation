#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main (){

  while(1){
    vector<int> point;
    int n,i,temp,sum;
    cin >> n;
    if (n==0)break;
    
    for(i=0;i<n;i++){
      cin >> temp;
      point.push_back(temp);
    }
    
    sort(point.begin(),point.end());
    
    sum = 0;
    
    for(i=1;i<n-1;i++){
      sum += point[i];
    }
    
    sum = sum / (n-2);
    
    cout << sum <<endl;
  }
  
  return 0;
}