#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
  char s[6];
  int len;

  scanf("%s", s);
  len = strlen(s);

  for (int i=0; i<len-1; i++) {
    if (s[i]=='A' && s[i+1]=='C') {
      printf("Yes");
      return 0;
    }
  }
  printf("No");

  return 0;
}