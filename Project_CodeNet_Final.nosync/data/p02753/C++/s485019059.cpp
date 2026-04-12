#include <iostream>
#include <string>

using namespace std;

int main(){
   string s;
   cin >> s;

   // cout << s.find('B') << endl;
   if((s.find('A') <= s.length()) & (s.find('B') <= s.length())){
      cout << "Yes" << endl;
   }
   else{
      cout << "No" << endl;
   }

   return 0;
}
