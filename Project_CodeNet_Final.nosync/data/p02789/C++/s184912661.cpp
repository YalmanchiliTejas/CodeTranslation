#include <iostream>
using namespace std;
int main()
{
    int N,M;
    cin>> N>>M;
    if ((N>=1 && N<=100) && (M>=0 && M<=N))
        if (N==M)
            cout<<"Yes";
        else
            cout<<"No";

    return 0;
}
