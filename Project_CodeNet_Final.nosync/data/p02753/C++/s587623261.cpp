#include <iostream>

using namespace std;

int main () {
   string S; cin >> S;
   string in;

   if(S[0] == S[1] && S[1] == S[2]) {
      in = "No";
   } else {
      in = "Yes";
   }

   cout << in << endl;
}
