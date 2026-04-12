#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int A,B,C,X,Y,n,k=0x7fffffff;
    cin>>A>>B>>C>>X>>Y;
    n=min(min(A,B),C);
    int t=max(max(A,B),C);
    for(int i=0; i<=100000;i++)
    {
       k=min(k,(i*2*C + max(0,X- i) *A + max(0, Y- i)*B));
    }
    cout<<k<<endl;
    return 0;
}

