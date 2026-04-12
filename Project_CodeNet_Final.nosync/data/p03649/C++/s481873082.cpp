#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
//deque/functional/iterator/list/map/memory/numeric/queue/set/stack/utility/vector
//#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[51];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int f=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>n-1){
			f=1;
        }
    }
    if(f==0){
		cout<<0<<endl;
		return 0;
    }

	ll y=0;
    ll k=0;
    while(1)
    {
        int max=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]>a[max])
            {
                max=i;
            }
        }
        if(a[max]<=n-1){
			break;
        }
        y=a[max]/n;
        for(int i=0; i<n; i++)
        {
            if(i==max)
            {
                a[i]=a[i]%n;
            }
            else
            {
                a[i]+=y;
            }
        }
		k=k+y;
    }

	cout<<k<<endl;
    return 0;
}
