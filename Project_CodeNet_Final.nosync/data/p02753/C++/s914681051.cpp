#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n;
char s[maxn];


int main()
{
    cin >> s;
    int len = strlen(s);
    int f = 0;
    for(int i = 0; i < len - 1; i ++)
      {
        if(s[i] == 'A' && s[i + 1] == 'B' || s[i] == 'B' && s[i + 1] == 'A'){
          f = 1;
          break;
        }
      }
    puts(f ? "Yes" : "No");
    return 0;
}
