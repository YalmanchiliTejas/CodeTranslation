#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  char s;
  cin>>s;
  string ans="consonant";
  if(s=='a'||s=='i'||s=='u'||s=='e'||s=='o') ans="vowel";
  cout<< ans <<endl;
}
