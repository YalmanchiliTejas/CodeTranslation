#include<iostream>
#include<string>
using namespace std;

void bubbleSort( int* a, string* b, int n )
{
    for( int i = 0; i < n; i++ )
        for( int j = n - 1; j >= i + 1; j-- )
        {
            if( a[j-1] < a[j] )
            {
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;

                string temp2 = b[j-1];
                b[j-1] = b[j];
                b[j] = temp2;
            }
        }

}

int main()
{   
    int n, a[10], b, c, cnt = 0;
    string s[10];

    while( cin >> n )
    {
        if( n == 0 )
            break;
        if( cnt != 0 )
            cout << endl;
        cnt++;
        for( int i = 0; i < n; i++ )
        {
            cin >> s[i] >> a[i] >> b >> c;
            a[i] = a[i] * 3 + c;
        }
        bubbleSort( a, s, n );
        for( int i = 0; i < n; i++ )
            cout << s[i] << ',' << a[i] << endl;
    }

    return 0;
}
