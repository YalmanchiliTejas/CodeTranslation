#include <bits/stdc++.h>

using namespace std;

void subsets(vector<int> S, int n) 
{
     int nSub = 1<<n;
     
     for(int i = 0; i < nSub; i++)
     {
         if(i == 0)
         {
            cout << i << ":\n"; 
         }
     	 else
     	 {
     	     cout << i << ":";
     	     
     	     for(int k = 0; k < n; k++)
             {
                 if((1 << k) & i)
                 {
                     cout << " " << S[k];
                 } 
             }
             cout << "\n";
     	 }
     }
}

int main() 
{
    int n;
    scanf("%d", &n);
    
    vector<int> v;
    
    for(int i = 0; i < n; i++)
        v.emplace_back(i);
        
    subsets(v, n);
    
    return 0;
}
