#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
 
using namespace std;
 

int main(){
  int X,Y,Z,sum=0,count=1;
  cin >> X >> Y >> Z;
  sum=Y+Z*2;
  while(sum<=X){
    sum+=Y+Z;
    count+=1;
  }
  cout << count-1 << endl;
}
