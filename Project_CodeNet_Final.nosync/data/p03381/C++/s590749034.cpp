#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int listt[n],ans[n];
    for(int i=0; i<n; i++)
        {scanf("%d",&listt[i]); ans[i]=listt[i];}
    sort(listt,listt+n);
    for(int i=0; i<n; i++)
    {
        if(ans[i]<=listt[n/2-1])
            printf("%d\n",listt[n/2]);
        else
            printf("%d\n",listt[n/2-1]);

    }

}