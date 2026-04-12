#include<bits/stdc++.h>
using namespace std;

int main(){
   int a, b, c;
   cin >> a >> b >> c;
   int val = a*100 + b*10 + c;
   if(val % 4)
      cout << "NO";
      else cout << "YES";
   return 0;
}