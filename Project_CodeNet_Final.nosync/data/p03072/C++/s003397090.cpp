#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   int num = 1;

   cin >> n;
   vector<int> h(n);

   for(int i=0;i<n;i++) cin >> h[i];

   for(int i=1;i<n;i++){
      int max = h[0];
      for(int j=0;j<i;j++){
         if(h[j] > max) max = h[j];
      }
      if(h[i] >= max) num++;
   }

   cout << num;

   return 0;
}
