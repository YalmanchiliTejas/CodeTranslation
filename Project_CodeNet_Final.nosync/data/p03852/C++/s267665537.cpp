#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<math.h>
#include<vector>
#include<cctype>
#include<string>
#include<set>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
std::string line;
typedef long long ll;

int main(){

   char c;
   cin >> c;

   if( (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')){
      cout << "vowel" << endl;
   }else{
      cout << "consonant" << endl;
   }


   return 0;
}