#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d,count=0;
  cin >> n;
  d = n;
  while((d-15)>=0){
    d = d-15;
    count++;
  }
  cout << n*800 -200*count << endl;
}