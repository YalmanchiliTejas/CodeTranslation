#include<iostream>
#include<string>
using namespace std;

void initializeDice( int* d )
{
    d[0] = 1;
    d[1] = 2;
    d[2] = 4;
    d[3] = 5;
    d[4] = 3;
    d[5] = 6;
}

void changePosition( int* d, int a, int b )
{
    int temp = d[a];
    d[a] = d[b];
    d[b] = temp;
}

int moveDice( int* d, string s )
{
    if( s == "North" )
    {
        changePosition( d, 0, 3 );
        changePosition( d, 0, 1 );
        changePosition( d, 1, 5 );
    }
    else if( s == "East" )
    {
        changePosition( d, 0, 4 );
        changePosition( d, 0, 2 );
        changePosition( d, 2, 5 );
    }
    else if( s == "West" )
    {
        changePosition( d, 0, 2 );
        changePosition( d, 0, 4 );
        changePosition( d, 4, 5 );
    }
    else if( s == "South" )
    {
        changePosition( d, 0, 1 );
        changePosition( d, 0, 3 );
        changePosition( d, 5, 3 );
    }
    else if( s == "Right" )
    {
        changePosition( d, 1, 2 );
        changePosition( d, 3, 1 );
        changePosition( d, 1, 4 );
    }
    else
    {
        changePosition( d, 1, 4 );
        changePosition( d, 3, 1 );
        changePosition( d, 1, 2 );
 
    }
    return d[0];
}

int main()
{
    int n;
    int dice[6];
    string str;

    while( cin >> n )
    {
        if( n == 0 )
            break;

        initializeDice(dice);

        int sum = 0;
        for( int i = 0; i < n; i++ )
        {
            cin >> str;
            sum += moveDice( dice, str );
        }
        cout << sum + 1 << endl;
    }

    return 0;
}
