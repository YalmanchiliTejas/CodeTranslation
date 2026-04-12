#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, c = 0, cost = 0;
    scanf("%d", &n);
    
    cost = n * 800;
    
    while(n >= 15)
    {
        n-=15;
        c++;    
    }
    
    cost -= c * 200;
    
    printf("%d\n", cost);
    return 0;
}