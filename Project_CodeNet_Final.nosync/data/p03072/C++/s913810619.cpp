#include <iostream>

using namespace std;

int main()
{
    int N,h[25],i,m,sum=1;
    cin>>N;
    for(i=0; i<N; i++)
        cin>>h[i];
    m=h[0];
    for(i=1; i<N; i++)
    {
        if(h[i]>=m)
        {
            m=h[i];
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
