#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int x = N*800;
    int c;
    if(N < 15)
    {
        c = x-0;
        cout << c <<endl;
    }
    else if(N >= 15 && N <  30)
    {
        c = x - 200;
        cout << c <<endl;
    }
    else if( N >= 30 && N < 45)
    {
        c = x - 2*200;
        cout <<c <<endl;
    }
    else if(N >= 45 && N < 60)
    {
        c = x - 3*200;
        cout << c <<endl;
    }
    else if(N >= 60 && N <  75)
    {
        c = x - 4*200;
        cout << c <<endl;
    }
    else if(N >= 75 && N <  90)
    {
        c = x - 5*200;
        cout << c <<endl;
    }
    else if(N >= 90 && N < 105)
    {
        c = x - 6*200;
        cout << c <<endl;
    }
    return 0;

}
