#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
typedef long long ll ;
ll s[N],arr[N];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin>>num;
    for(int i = 1;i<=num;i++)
    {
        ll temp;
        cin>>temp;
        arr[i]=temp;
        if(i==1)
            s[i]=temp;
        else
            s[i]=(s[i-1]+temp);
    }
    ll he = 0;
    for(int i =1;i<=num;i++)
    {
        he+=((s[num]-s[i])%mod)*arr[i];
        he=he%mod;
    }
    cout<<he<<endl;


}
