#include<iostream>
using namespace std;

int main()
{
    int N, h = 0, t = 0;

    cin >> N;

    int H[N];

    for( int i = 0; i < N; i++ )
    {
        cin >> H[i];
    }

    for( int i = 0; i < N; i++ )
    {
        if( h <= H[i] )
        {
            h = H[i];
            t++;
        }
    }

    cout << t << endl;

}

