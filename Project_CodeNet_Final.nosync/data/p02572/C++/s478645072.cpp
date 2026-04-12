#include<bits/stdc++.h>

using namespace std;
//a mnogo kokaina znaci to da nisi miran
const int maxi =1e6+10;
#define pb push_back
#define pii pair<int,int>
const long long mo = 1e9+7;
int a[maxi];
string s;
int n;
vector<int> v[maxi];

int main()
{
    long long sum = 0;
    cin>>n;
    for (int i  =1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        sum%=mo;
    }
    long long ans = 0;
    for (int i = 1;i<=n;i++)
    {
        ans+= (sum - a[i])*a[i];
        ans%=mo;
        if (ans<0) ans+=mo;
    }

    ans*=(mo+1)/2;
    ans%=mo;
    cout<<ans<<endl;

    return 0;
}
