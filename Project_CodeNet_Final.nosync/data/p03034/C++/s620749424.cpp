/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
lli a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0;lli res=0ll;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=1;(i+1)<=n;++i)
    {
        lli temp=0ll,curr=0ll;
        int l=0,r=n-1;
        if((n-1)%i==0)
        {
            while(l<r)
            {
                curr+=(a[l]+a[r]);
                temp=max(temp,curr);
                l+=i;r-=i;
            }
        }
        else
        {
            while((l+1)<n&&(r>i))
            {
                curr+=(a[l]+a[r]);
                temp=max(temp,curr);
                l+=i;r-=i;
            }
        }
        res=max(res,temp);
    }
    cout<<res<<endl;
}