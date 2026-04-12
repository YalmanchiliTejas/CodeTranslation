#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int d[300000];
    for(int i=0;i<N;i++)
    {
        cin>>d[i];
    }
    int D = 0;
    for (int i = 0; i < N-1; i++)
    {D=max(D,d[i]);
    if(D<10)
    {
        cout<<"no"<<endl;
        return 0;
    }
    D-=10;
        /* code */
    }
    D=0;
    for (int i = N-1; i>0; i--)
    {D=max(D,d[i]);

    if(D<10)
    {
        cout<<"no"<<endl;
        return 0;
    }
    D-= 10;
        /* code */
    }
    
    cout<<"yes"<<endl;
    return 0;
    
}
