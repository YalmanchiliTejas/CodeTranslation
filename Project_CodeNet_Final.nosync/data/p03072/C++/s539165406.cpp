#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

#define kuriage(x)  x+=10-x%10;
#define mod(cans) cans%10**9+7;
#define cin_pl(x,y) for(int i=0;i<x;i++){cin>>y[i];}
#define debug(x) cout << "Debug" << x << "\n"

typedef long long ll;


using namespace std;
int main()
{
    int n;
    cin>>n;
    int h[n],ans=1,r;
    cin_pl(n,h);
    r=h[0];
    for(int i=1;i<n;i++)
    {
        if(r<=h[i])
        {
            ans++;
            r=h[i];
        }
    }
    cout<<ans;
}