#include<bits/stdc++.h>
const int  mod = 1e9 + 7;
#define debug(x) cout << '>' << #x << ':' << x << endl;

using namespace std ;
int main()
{
    long int n;
    cin >> n;
    long int arr[n];
    long int suf[n]={0};

    for(int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
    suf[0] = arr[0];

    for(int i = 1; i < n; i++)
        {
            suf[i] = arr[i]+suf[i-1];
        }
    long long int res = 0;

    for(int i = 0; i < n ; i++)
            {
                res += ((suf[n-1]-suf[i])%mod*arr[i]%mod)%mod;
            }
    cout<<res%mod;
}

