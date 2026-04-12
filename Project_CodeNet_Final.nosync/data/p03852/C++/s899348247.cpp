#include <iostream>

using namespace std;

int main()
{
string s;
cin >>s;
for (int i=0;i<s.size();i++){
   if (s[i]=='i'||s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='u'){
     cout<<"vowel";
   }else{
     cout<<"consonant";
   }
}

   return 0;
}