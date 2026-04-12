#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
    ll k,a,b;
    cin>>k>>a>>b;
    ll ans;
    if(a >= k)ans = 1;
    else if(a <= b)ans = -1;
    else if((2 * k - a - b) % (a - b) == 0)ans = (2 * k - a - b) / (a - b) % 2 == 1?(2 * k - a - b) / (a - b):(2 * k - a - b) / (a - b) + 1;
    else ans = (2 * k - a - b) / (a - b) % 2 == 1?(2 * k - a - b) / (a - b) + 2:(2 * k - a - b) / (a - b) + 1;
    cout<<ans<<endl;
    return 0;
}
