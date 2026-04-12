#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define mod 1000000007
#define INF 1000000000000000


int main()
{

    int n;
    scanf("%d",&n);
    int ara[n+5];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    int ans=1;
    vector<int> vp;
    vp.pb(-ara[0]);

    for(int i=1;i<n;i++)
    {
        int y=upper_bound(vp.begin(),vp.end(),-ara[i])-vp.begin();
        if(y==vp.size())
        {
            ans++;
            vp.pb(-ara[i]);
        }
        else{
            vp[y]=-ara[i];
        }


    }
    printf("%d",ans);
}



