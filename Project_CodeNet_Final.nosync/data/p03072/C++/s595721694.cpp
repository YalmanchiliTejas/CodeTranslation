#include <iostream>

using namespace std;

int main()
{
    int N;
    while(cin>>N)
    {
        int a[20];
        int i;
        for(i=0;i<N;i++)
            cin>>a[i];
            int hmax=a[0],cnt=0;
        for(i=0;i<N;i++)
        {
            if(a[i]>=hmax)
                cnt++;
            hmax=hmax>a[i]?hmax:a[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}