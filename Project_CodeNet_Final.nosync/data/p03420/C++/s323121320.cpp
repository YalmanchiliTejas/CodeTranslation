# include <iostream>
# include <cstdio>

using namespace std;

const int inf = 1e9 + 7;
const int N = 1e6 + 5;

int n, k;
long long ans;

int main(){
      scanf("%d %d", &n, &k);

      for(int b = k + 1; b <= n; b ++){
            if(k == 0)
                  ans += max(0, b - k - 1);
            else
                  ans += b - k;
            for(int a = b; a <= n; a += b){
                  int l = a + k, r = a + b - 1;
                  r = min(n, r);
                  ans += max(r - l + 1, 0);
            }
      }

      printf("%lld\n", ans);
}
