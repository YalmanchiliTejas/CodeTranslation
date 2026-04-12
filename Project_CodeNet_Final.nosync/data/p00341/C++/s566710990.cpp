#include<iostream>
using namespace std;

int main()
{
    int a[101] = {0}, b;
    
    for( int i = 0; i < 12; i++ )
    {
        cin >> b;
        a[b]++;
    }
    
    int cnt = 0;
    for( int i = 1; i < 101; i++ )
        cnt += a[i] / 4;

    if( cnt == 3 )
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
