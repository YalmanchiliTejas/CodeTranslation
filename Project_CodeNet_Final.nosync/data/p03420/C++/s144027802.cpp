#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
//set<int>::iterator it
using namespace std;
typedef long long ll;
ll n,k,sum,a,b;
int main()
{
    cin>>n>>k;
    if(k==0)sum=n*n;
    else
    ff(i,k+1,n)
    {
        b=i;
        ll now=n/b,re=n%b;
        if(re<=k-1) sum+=now*(b-k);
        else
        sum+=((now+1)*(re+1-k)+now*(b-re-1));
    }
    cout<<sum<<endl;
    return 0;
}
