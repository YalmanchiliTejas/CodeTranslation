#include <iostream>

using namespace std;

int main()
{
   char s[3];
   int i;
   cin >> s;
   if(s[0] == s[1] && s[0]==s[2] ) cout << "No";
   else cout << "Yes";
   return 0;
}