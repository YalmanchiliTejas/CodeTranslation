#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(void)
{
    LL n,k;
    cin>>n>>k;
    if(k == 0)
        cout<<n*n<<endl;
    else
    {
        LL sum = 0;
        for(int i = k; i <= n; i++)
        {
            LL u_int = n/i;
            sum += u_int*(i - k);
            if(n%i >= k)
                sum += n%i - k + 1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
