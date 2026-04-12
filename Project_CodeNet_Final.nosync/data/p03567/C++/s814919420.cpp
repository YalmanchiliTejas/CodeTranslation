#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

#define _int64 long long

char s[1000];

int main()
{
  int i,l;
  scanf("%s",s);
  l=strlen(s);
  for (i=0;i+1<l;i++)
    if ((s[i]=='A')&&(s[i+1]=='C'))
    {
      printf("Yes\n");return 0;
    }
  printf("No\n");
  return 0;
}