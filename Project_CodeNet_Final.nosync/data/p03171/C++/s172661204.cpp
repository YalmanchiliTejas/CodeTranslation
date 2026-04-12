#include <iostream>
#include <cmath>
#include <string.h> 
#include <vector>
#include <bits/stdc++.h> 
#include <iomanip>
#include<algorithm> 
#include <string> 
using namespace std;

int main(){
    int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long int table[n][n];
    for (int gap = 0; gap < n; ++gap)
    {
        for (int i = 0, j = gap; j < n; ++i, ++j)
        {
            long long int x = ((i+2) <= j) ? table[i+2][j] : 0;
            long long int y = ((i+1) <= (j-1)) ? table[i+1][j-1] : 0;
            long long int z = (i <= (j-2))? table[i][j-2]: 0;
 
            table[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
        }
    }
   long long int S=0;
   for(int i=0;i<n;i++){ S += a[i];}
   long long int X= table[0][n-1];
   long long int Y = S-X;
   cout<<X-Y;
}
