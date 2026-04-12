#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;
  int flag;
  int x;
  x=0;

int l, i=1, a[n];
a[0]= 0;
  while(cin>>l){
        a[i] = l;
      flag = 0;  
   for(int k=i-1;k >= 0;k--){  
          
   if(a[i] < a[k]){
       flag=1;
      break;
   }
        }
  if(flag==0){x=x+1;}
  i++;
  }
 
 cout << x;

}