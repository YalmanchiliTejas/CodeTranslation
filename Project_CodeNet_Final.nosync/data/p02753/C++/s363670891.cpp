#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main(void){
    // Your code here!
   string a;
   cin >> a;
   char b = a[0];
   for(char f:a){
       if(b!=f){
           cout << "Yes" << endl;
           return 0;
       }
   }
   cout << "No" << endl;
}
