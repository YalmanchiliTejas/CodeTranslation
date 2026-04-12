#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <utility>
#include <map>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
vector<ll> a;
const ll INF = 1e16;

int main()
{
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        bool can=true;
        for(int j=0;j<i;j++)
        {
            if(h[j]>h[i])
                can=false;
        }
        if(can==true)
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}


