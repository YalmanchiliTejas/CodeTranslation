# include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, a[N], b[N];

int main(){
      scanf("%d", &n);

      for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
            b[i] = a[i];
      }

      sort(b + 1, b + n + 1);

      for(int i = 1; i <= n; i ++){
            if(a[i] <= b[n / 2])
                  cout << b[n / 2 + 1] << endl;
            else
                  cout << b[n / 2] << endl;
      }
}
