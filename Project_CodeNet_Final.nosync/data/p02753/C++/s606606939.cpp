#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

int main (){
    string S;
    cin >> S;
    string ans = "No";

   if(S[0] == 'A'){
        if(S[1] == 'B' || S[2] == 'B') ans = "Yes";
   } else {
        if(S[1] == 'A' || S[2] == 'A') ans = "Yes";
   }
   
   cout << ans << endl;

}