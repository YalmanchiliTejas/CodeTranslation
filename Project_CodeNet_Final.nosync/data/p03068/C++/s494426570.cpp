#include <iostream>

using namespace std;
int main()
{
    int a;
    string b;
    int c;
    cin>>a>>b>>c;
    for (int i=0; i<a; i++)
    {
        if (b[i]!=b[c-1])
        {
            b[i]='*';
        }
    }
    cout<<b;
    
    return 0;
}