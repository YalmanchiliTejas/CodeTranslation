#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;

int n, arr[maxn];

int main(){
   cin >> n;
   for (int i = 0; i < n; i++) cin >> arr[i];
   for (int i = n - 1; i >= 0; i -= 2) printf("%d ", arr[i]);
   for (int i = (n % 2); i < n; i += 2) printf("%d ", arr[i]);
   return 0;
}