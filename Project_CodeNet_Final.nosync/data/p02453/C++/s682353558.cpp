#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m, i;
    scanf("%d", &n);
    
    vector<int> v;
    
    for(i = 0; i < n; i++)
    {
        scanf("%d", &m);
        v.emplace_back(m);
    }
    
    scanf("%d", &m);
    
    for(i = 0; i < m; i++)
    {
        scanf("%d", &n);
        printf("%d\n", lower_bound(v.begin(), v.end(), n) - v.begin());
    }
    
    return 0;
}
