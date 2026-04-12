#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main()
{
        while(true)
        {
                int n,A[100]={0};
                cin>>n;
                if(n==0) break;
                rep(i,n) cin>>A[i];
                sort(A,A+n);

                int sum=0;
                rep(i,n-2) sum+=A[i+1];
                cout<<sum/(n-2)<<endl;
        }
        return 0;
}