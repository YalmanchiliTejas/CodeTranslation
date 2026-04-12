#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int main()
{
  int n = 0;
  scanf("%d", &n);
  vector<int> a(n, 0);
  for(int i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  long long arr[n][n];
  memset(arr, 0, sizeof arr);
  for(int i=0; i<n; i++){
    arr[i][i] = a[i];
  }
  for(int j=1; j<n; j++){
    for(int i=0; i<n-j; i++){
      arr[i][i+j] = max(a[i] - arr[i+1][i+j], a[i+j] - arr[i][i+j-1]);
    }
  }
  printf("%lld\n", arr[0][n-1]);
}
