#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

char c;

set<char> st;

int main()
{
   st.insert('a');
   st.insert('e');
   st.insert('i');
   st.insert('o');
   st.insert('u');

   cin >> c;

   if(st.count(c))
   {
       cout << "vowel" << endl;
   }
   else
   {
       cout << "consonant" << endl;
   }
}