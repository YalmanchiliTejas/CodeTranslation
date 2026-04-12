#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int a[MAXN + 1];
//int b[3 * MAXN + 1];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i,n,p;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
   for(i = n; i >= 1; i -= 2)
        cout << a[i] << " ";
   if(n % 2 == 0)
      p = 1;
   else
      p = 2;
   for(i = p; i <= n; i += 2)
    cout << a[i] << " ";
   cout << endl;
 //   cin.close();
 //   cout.close();
    return 0;
}
