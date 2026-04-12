#include <bits/stdc++.h>
#include <cstdint>
#include <sys/time.h>

typedef std::int_fast32_t  s32;
typedef std::uint_fast32_t u32;
typedef std::int_fast64_t  s64;
typedef std::uint_fast64_t u64;

const unsigned long mod = 1000000007;

int expr(void);
int term(void);
int num(void);

char str[262144];
int i;

int expr(void) {
  int res = term();
  while( str[i] == '+' ) {
    i += 1;
    int temp = term();
    res += temp;
  }
  return res;
}

int term(void) {
  int res = num();
  while( str[i] == '*' ) {
    i += 1;
    int temp = num();
    res *= temp;
  }
  return res;
}

int num(void) {
  int res = 0;
  while( '0' <= str[i] and str[i] <= '9' ) {
    res = res * 10 + (str[i] - '0');
    i += 1;
  }
  return res;
}

int expr2(void) {
  int res = num();
  while( str[i] == '+' or str[i] == '*' ) {
    char ope = str[i];
    i += 1;
    int temp = num();
    if( ope == '+' ) {
      res += temp;
    }
    else {
      res *= temp;
    }
  }
  return res;
}                                           

int main() {

  int bob;
  bool ans[2] = {false, false};
  
  scanf("%s", str);
  scanf("%d", &bob);

  i = 0;
  if( bob == expr() ) {
    ans[0] = true;
  }

  i = 0;
  if( bob == expr2() ) {
    ans[1] = true;
  }

  if( ans[0] and not ans[1] ) {
    std::cout << "M" << std::endl;
  }
  else if( not ans[0] and ans[1] ) {
    std::cout << "L" << std::endl;
  }
  else if( ans[0] and ans[1] ) {
    std::cout << "U" << std::endl;
  }
  else {
    std::cout << "I" << std::endl;
  }
  
  return 0;
}