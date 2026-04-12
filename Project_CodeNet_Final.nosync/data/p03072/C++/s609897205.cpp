#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    int maxs=a[0];
    int sum=1;
    for(int i=1; i<n; i++)
        if(a[i]>=maxs)
        {
            sum++;
            maxs=a[i];
        }
        cout<<sum<<endl;
    return 0;
}
