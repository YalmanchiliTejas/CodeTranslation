//Artie WANG
//io
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

//data structure
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
//#include <unordered_map>
//#include <unordered_set>
#include <utility>
#include <bitset>
#include <complex>




using namespace std;

const char newline = '\n';
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l4;


const int maxn = 2e5+1;
int n, a[maxn], b[maxn];

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    {
      scanf("%d", a+i);
    }
  int cur = n;
  int pos = 1;
  while (cur > 0)
    {
      b[pos++] = cur;
      cur -= 2;
    }
  pos = n;
  cur = n-1;
  while (cur > 0)
    {
      b[pos--] = cur;
      cur -= 2;
    }
  for (int i = 1; i <= n; ++i)
    {
      if (i != 1)
	{
	  printf(" ");
	}
      printf("%d", a[b[i]]);
    }
  puts("");

}
