#include <bits/stdc++.h>
using namespace std;

int main() 
{
   char c;
   cin >> c;

   vector<char> v(5);
   v = {'a', 'i', 'u', 'e', 'o'};

   bool frag = false;
   for (int i = 0; i < 5; i++)
   {
      if (c == v.at(i))
         frag = true;
   }

   if (frag)
      cout << "vowel" << endl;
   else
      cout << "consonant" << endl;
}
