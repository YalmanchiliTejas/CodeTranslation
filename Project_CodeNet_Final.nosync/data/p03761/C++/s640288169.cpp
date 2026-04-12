#include <cstdio>
#include <cstring>
#include <algorithm>

int max[26];

int main()
{
  int n;
  scanf("%d", &n);
  char s[51];
  int count[26];
  memset(max, 0x7F, 26 * sizeof(int));
  for (int i = 0; i < n; ++i)
  {
    memset(count, 0, 26 * sizeof(int));
    scanf("%s", s);
    for (char *p = s; *p; ++p)
    {
      count[*p - 'a']++;
    }
    for (int j = 0; j < 26; ++j)
    {
      max[j] = std::min(max[j], count[j]);
    }
  }
  for (int i = 0; i < 26; ++i)
  {
    while (max[i] > 0)
    {
      putc(i + 'a', stdout);
      max[i]--;
    }
  }
  puts("");
  return 0;
}
