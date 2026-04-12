#include "iostream"
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <cctype>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
using ll=long long;
#define MOD  1000000007

int main(int argc, char const *argv[]) {
  char s;
  std::cin >> s;
  if(s=='a' || s=='i' || s=='u' || s=='e' || s=='o') std::cout << "vowel" << '\n';

  else std::cout << "consonant" << '\n';
  
  return 0;
}