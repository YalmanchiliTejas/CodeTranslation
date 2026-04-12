#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<bitset>
#define endl "\n"
using namespace std;

int main()
{

  char c;
  scanf("%s", &c);
  if (c == 97 || c == 105 || c == 117 || c == 101 || c == 111)
  {
    printf("%s\n", "vowel");
  }
  else
  {
    printf("%s\n", "consonant");
  }
  return 0;
}
