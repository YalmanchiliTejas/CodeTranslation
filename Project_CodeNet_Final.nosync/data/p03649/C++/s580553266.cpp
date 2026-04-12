#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    cin >> n;
    vector<long long> ni(n);
    vector<long long> ni2(n);
    int t;
    long long k=0;
    for(t=0;t<n;t++)
        cin >> ni[t];
    while(1)
    {
        long long a=0;
        for(t=0;t<n;t++)
        {
            ni2[t] = ni[t]/n;
            a += ni2[t];
            ni[t] %= n;
        }
        if(a == 0)  break;
        k += a;
        for(t=0;t<n;t++)
        {
            int t1;
            for(t1=0;t1<n;t1++)
            {
                if(t != t1)
                    ni[t] += ni2[t1];
            }
        }
    }
    cout << k << endl;
    return 0;
}
