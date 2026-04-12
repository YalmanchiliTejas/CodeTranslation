#include <iostream>

using namespace std;
int N,K,a,b,q;
long long sol;
int main()
{
    cin>>N>>K;
    for(b=K+1;b<=N;b++)
    {
        q=(N+1)/b -1;
        sol=sol+(q+1)*(b-K);
        a=(q+1)*b+K;
        if(a<=N) sol=sol+min(N-a+1,b-K);
    }
    if(K==0) sol-=N;
    cout<<sol;
    return 0;
}
