#include <stdio.h>
#include <vector>
#include <math.h>
#include <iostream>
 int main(){

     using namespace std;
     
     string s;
     cin >> s;
     
     if(s[0] == s[1] && s[1] == s[2])
     {
         cout << "No" << endl;
     } else {
         cout << "Yes" << endl;
     }
     
     
     return 0;
    
}
