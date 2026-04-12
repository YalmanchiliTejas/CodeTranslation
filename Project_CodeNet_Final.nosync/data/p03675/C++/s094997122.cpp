#include <cstdio>
#include <cstdlib>

#define MAX_N (2*100000)

using namespace std;

int a[MAX_N + 10];

int main() {
  int n;
  scanf("%d", &n);

  for(int i=0;i<n;++i){
    scanf("%d", &a[i]);
  }

  int it = n - 1;
  for(int i=0;i<n;++i){
    if ( it < 0 ) {
      printf("%d ", a[-it-1]);
    } else {
      printf("%d ", a[it]);
    }
    it -= 2;
  }

  return 0;
}