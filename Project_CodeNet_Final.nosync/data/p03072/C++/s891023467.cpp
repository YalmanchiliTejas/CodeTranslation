#include <iostream>

using namespace std;

int main()
{
    int n,shuzu[20];
    cin >> n;
    int a=0,b;
    while(a<n)
    {
        cin >> b;
        shuzu[a]=b;
        a++;
    }
    int m=shuzu[0],num=1;
    for(int i=1;i<n;i++)
    {
        if(shuzu[i]>=m)
        {
            m=shuzu[i];
            num++;
        }
    }
    cout << num << endl;
}
