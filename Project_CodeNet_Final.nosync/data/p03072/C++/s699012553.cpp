#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int H[n];
    int b = n;
    for(int i=0;i<n;i++)
    cin >> H[i];

    int a = H[0];

    for(int j=1;j<n;j++)
    {
        if(a <= H[j])
            a = H[j];
        else
        {
            b--;
        }
    }

    cout << b  << endl;
    return 0;
}