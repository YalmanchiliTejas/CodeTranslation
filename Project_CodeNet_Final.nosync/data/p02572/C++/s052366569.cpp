#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int main()
{
  int n = 0;
  long long base = 1e9+7;
  scanf("%d", &n);
  vector<long long> a(n, 0);
  for(int i=0; i<n; i++){
    scanf("%lld", &a[i]);
  }
  long long cumsum = 0;
  long long result = 0;
  for(int j=1; j<n; j++){
    cumsum = (cumsum + a[j-1]) % base;
    result = (result + cumsum * a[j]) % base;
  }
  printf("%lld\n", result);
}
