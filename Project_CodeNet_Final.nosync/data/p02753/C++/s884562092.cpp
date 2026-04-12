#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main() {
   string s;
	int a(0),b(0);
   cin >> s;

   for(int i = 0; i < 3;i++){
      if(s.at(i) == 'A'){
         a = 1;
        //cout <<s.at(i);;
      }
      if(s.at(i) == 'B'){
         b = 1;
      }
   }

   if(a == 1 && b == 1){
      cout << "Yes";
   }else{
      cout << "No";
   }

   
}
