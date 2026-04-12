#include <iostream>
#include <string>
//#include <cstdio>
int main()
{
  int N, K;
  char s[N+1];
  //std::string s;
  std::cin >> N >> s >> K;
  //scanf("%d\n%s\n%d", N, s, K);

  for (int i=0; i<N; i++) {
    if (s[i] != s[K-1]) s[i] = '*';
  }
  std::cout << s;
  //printf("%s", s);
  return 0;
}
