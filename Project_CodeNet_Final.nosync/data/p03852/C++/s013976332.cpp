#include <iostream>
#include <cstring>
using namespace std;
int main()
{
   char c;
   cin>>c;
   if(((int)c==97)||((int)c==101)||((int)c==105)||((int)c==111)||((int)c==117)) cout<<"vowel";
   else cout<<"consonant";
   return 0;
}
