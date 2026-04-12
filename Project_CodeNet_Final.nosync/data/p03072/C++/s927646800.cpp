#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int n,m,k,i,p; //mとpは高さ、nは個数、iは回数、kは答えの回数
 i=0;
 m=0;
 k=0;
 cin >> n,m;
 while (i<n){
  i++;
  cin>>p;
  if (m<=p){
   m=p;
   k++;
  }
 }
 cout << k;
}