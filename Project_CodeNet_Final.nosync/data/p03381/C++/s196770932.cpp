#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+100;
int a[maxn],b[maxn];
int main()
{
    int N;
    while(cin>>N)
    {
        for(int i=0; i<N; i++)
            cin>>a[i],b[i]=a[i];
        sort(a,a+N);
        int t=(N-1)/2;
        for(int i=0; i<N; i++)
        {
            //int pos=lower_bound(a,a+N,a[t])-a;
            //  int x=upper_bound(a,a+N,a[t])-a;
            int pos=t;
            if(b[i]<=a[pos]) pos++;

            //  if(b[i]<=a[x]) pos=x+1;
            //int x=
            cout<<a[pos]<<endl;
        }
    }

    return 0;
}
