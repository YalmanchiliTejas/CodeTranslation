#include <iostream>

using namespace std;

int main()
{
   int N;
   cin >> N;
    
   int h[20] = {0};
   for (int i = 0; i < N; ++i)
       cin >> h[i];
   int total = 1;
   for (int i = 1; i < N; ++i)
   {
       bool flag = true;
       for (int j = i; j > 0; --j)
           if (h[i] < h[j-1])
           {
               flag = false;
               break;
           }
       if (flag)
           total++;
   }

   cout << total << endl;
   return 0;
}
