#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main()
{
   int n, i;
   cin >> n;
   int a[n];

   for(int i=0; i<n; i++)
   	cin>> a[i];

   int m = a[0];
   int ans = 1;

   for(int i=1; i<n; i++)
   {
   		m = max(m,a[i]);
   		if(a[i]>=m)
   			ans++;
   }

   cout<<ans;
   
   cout << endl;
   return 0;
}
 