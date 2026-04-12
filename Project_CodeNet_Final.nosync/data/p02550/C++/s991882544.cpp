#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;
    
int main() {

    long long n,x,m; cin >> n >> x >> m;
    vector<long long> id(m,-1);
    vector<long long> ans(m,0);
    long long res;
    long long j = 0;
    long long len =0;
    while (id[x] == -1)
    {
        id[x] = len;
        ans.at(j) = x;
        x = (x*x)%m;
        len++;
        j++;
    }

    long long loop; loop = len - id[x];
    long long count; count = (n-id[x])/loop;
    long long value=0;
    for(long long i = id[x] ; i < len ; i++){
        value += ans[i];
    }

////////////////ここまではできてるはず


    res = 0;
    if (n < len)
    {
        res = 0;
        for (long long i = 0; i < n; i++)
        {
            res += ans[i];
        }
        
    }
    else
    {
        for (long long i = 0; i < id[x]; i++)
        {
            res += ans[i];
        }
        res = res + count * value;
        long long amari = (n-id[x])%loop + id[x];
        for (long long i = id[x]; i < amari; i++)
        {
            res += ans[i];
        } 
    }
    



    
    cout << res << endl;
    

return 0;

}