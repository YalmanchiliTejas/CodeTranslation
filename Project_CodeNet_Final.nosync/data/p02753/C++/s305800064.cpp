#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#define ll long long

using namespace std;


int main(void){
   string s;
   cin >> s;
   if(s[0]==s[1] && s[1]==s[2])
      cout << "No" << endl;
   else
   {
      cout << "Yes" << endl;
   }

   return 0;
}
