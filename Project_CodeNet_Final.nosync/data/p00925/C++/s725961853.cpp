#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string a;
    int b, x[3], res1, res2 = 0;
    stack<int> s, t;

    cin >> a >> b;

    for( int i = 0; i < a.size(); i++ )
    {
        s.push(a[i]-'0');
        if( s.size() == 3 )
        {
            for( int j = 0; j < 3; j++ )
            {
                x[j] = s.top();
                s.pop();
            }
            if( x[1] == '+' - '0' )
                s.push( x[0] + x[2] );
            else
                s.push( x[0] * x[2] );
        }
    }

    res1 = s.top();

    t.push(a[0]-'0');
    for( int i = 2; i < a.size(); i++ )
    {
        if( a[i-1] == '+' )
            t.push(a[i]-'0');
        if( a[i-1] == '*' )
        {
            x[0] = t.top(); t.pop();
            t.push(x[0]*(a[i]-'0'));
        }
    }

    while( !t.empty() )
    {
        res2 += t.top();
        t.pop();
    }

    if( b == res1 && b != res2 )
        cout << 'L';
    else if( b != res1 && b == res2 )
        cout << 'M';
    else if( b == res1 && b == res2 )
        cout << 'U';
    else
        cout << 'I';
    
    cout << endl;

    return 0;
}
