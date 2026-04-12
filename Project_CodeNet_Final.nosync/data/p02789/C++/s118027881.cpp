#include <iostream>
using namespace std;

int main()
{
    int n;
    int m;
    cin>>n>>m;
    if(n>=1 && n<=100)
    {
        if(m>=0 && m<=n)
        {
            if(n==m)
            {
                cout<<"Yes";
            }
            else{
                    cout<<"No";
            }
        }
    }


    return 0;
}
