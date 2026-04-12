#include <iostream>

using namespace std;

int main()
{
    int n,h;
    int m = 0;
    int a[21]={};
    cin>>n;
    for(int i = 0;i < n;i ++)
    {
        int cnt = 0;
        cin>>h;
        a[i] = h;
        for(int j = 0;j < i;j ++)
        {
            if(a[i]>=a[j])
                cnt++;
            else
                break;
        }
        if(cnt >= i)
            m++;

    }
    cout<<m;
    return 0;
}