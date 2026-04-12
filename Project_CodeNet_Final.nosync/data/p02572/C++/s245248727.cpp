#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define MAX 105
#define int long long int
int power(int a,int  n,int m)
{
    int res=1;
    while(n)
    {
        if(n&1)
        {
            res = ((res%m)*(a%m))%m;
            n--;
        }
        else
        {
            n/=2;
            a = ((a%m)*(a%m))%m;
        }
    }
    return res;
}
const int m = 1000000007;
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
  
    if (m == 1)
      return 0;
  
    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;
  
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
  
        // Update y and x
        y = x - q * y;
        x = t;
    }
  
    // Make x positive
    if (x < 0)
       x += m0;
  
    return x;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    int temp1 = 0;
    for(auto it: a)
    {
        temp1  = ((temp1%m)+(it%m))%m;
    }
    temp1 = power(temp1,2,m)%m;
    int temp2=0;
    for(int i = 0 ; i < n ; i++)
    {
        a[i] = power(a[i],2,m)%m;
    }
    for(int i = 0 ; i < n ; i++)
    {
        temp2  = ((temp2%m)+(a[i]%m))%m;
    }
    if(temp1<temp2)
    {
        temp1+=m;
    }
    int ans = (temp1-temp2)%m;
    
    int ans2 = modInverse(2,m);
    
    ans =((ans%m)*(ans2%m))% m;
    cout << ans;
    
    return;
}

int32_t main()
{
    int T = 1;
    //cin >> T;
    for(int i = 1 ; i <= T ; i++)
        solve();
    
    return 0;
}
/*
 AtCoder after Google Online Challenge Fail:(
 */
