#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main()
{
    ll n,ans = 0 ,rem = 0;
    cin >> n;
    ans = n*800 ;
    rem = n/15;
    cout << (ans-rem*200) << endl;
    return 0;
}
