#include <iostream>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;


map<char, int> mymap;
int main(int argc, char const* argv[])
{
    //0なら左　1なら右
    mymap['a'] = 0;
    mymap['b'] = 0;
    mymap['c'] = 0;
    mymap['d'] = 0;
    mymap['e'] = 0;
    mymap['f'] = 0;
    mymap['g'] = 0;
    mymap['h'] = 1;
    mymap['i'] = 1;
    mymap['j'] = 1;
    mymap['k'] = 1;
    mymap['l'] = 1;
    mymap['m'] = 1;
    mymap['n'] = 1;
    mymap['o'] = 1;
    mymap['p'] = 1;
    mymap['q'] = 0;
    mymap['r'] = 0;
    mymap['s'] = 0;
    mymap['t'] = 0;
    mymap['u'] = 1;
    mymap['v'] = 0;
    mymap['w'] = 0;
    mymap['x'] = 0;
    mymap['y'] = 1;
    mymap['z'] = 0;
    string s;
    while ( cin >> s && s != "#" ) 
    {
        int count = 0;
        char pre, next;        
        next = s[0];
        for (int i = 0; i < s.length() - 1; i++) 
        {
            pre = next;
            next = s[i+1];
            if ( (mymap[pre] + mymap[next]) % 2 == 1)
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}