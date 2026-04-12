#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,a[(int)1e5+10];
int cnt,que[(int)1e5+10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int i,j,num[2]={0,0};
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cnt=0,que[0]=-100000;
    for(i=n-1;i>-1;i--)
    {
        if(a[i]>=que[cnt])
            que[++cnt]=a[i];
        else
        {
            int l=1,r=cnt,mid;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(a[i]>=que[mid])
                    l=mid+1;
                else
                    r=mid-1;
            }
            que[l]=a[i];
        }
    }
    printf("%d\n",cnt);
    return 0;
}


/*

5
2 1 4 3 0

5
2 1 4 5 3


*/
