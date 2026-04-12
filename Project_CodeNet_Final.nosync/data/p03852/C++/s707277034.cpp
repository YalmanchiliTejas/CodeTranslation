#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
   string a;
   cin>>a;
   if(a.find_first_of("aeiou")==-1)
      cout<<"consonant";
   else
      cout<<"vowel";
   cout<<nl;
    return 0;
}
