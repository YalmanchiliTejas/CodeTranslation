#include<iostream>
#include<map>
using namespace std;
typedef long long LL;
const int N = 2e5;
LL a[N+1];
int main()
{
    LL n, x, m; cin >> n >> x >> m;
    LL todo = n;
    LL ans = 0;
    map<LL,int> first_saw;
    a[1] = x;
    int i;
    for(i = 1; i <= n && first_saw.find(a[i])==first_saw.end(); i++)
    {
        first_saw[a[i]] = i;
        ans += a[i];
        a[i+1] = (a[i]*a[i])%m; 
        todo--;
    }

    if(i <= n)
    {
        LL period = i-first_saw[a[i]];
        LL s = 0;
        for(int j = first_saw[a[i]]; j < i; j++)
            s += a[j];

        ans += (todo/period)*s;
        todo %= period;
        for(int k = 0; k < todo; k++)
            ans += a[first_saw[a[i]]+k];
    }
    cout<<ans<<endl;

    return 0;
}