// c++11 ~
#include <iostream>
#include <string>
#include <set>
using namespace std;

int position(char x)
{
    set<char> left;
    left.insert('q');
    left.insert('a');
    left.insert('z');
    left.insert('w');
    left.insert('s');
    left.insert('x');
    left.insert('e');
    left.insert('d');
    left.insert('c');
    left.insert('r');
    left.insert('f');
    left.insert('v');
    left.insert('t');
    left.insert('g');
    left.insert('b');

    // cout << "x is " << x << endl;
    if(left.count(x) == 1)
    {
        // cout << "left" << endl;
        return -1;
    }
    else
    {
        // cout << "right" << endl;
        return +1;
    }
}

int main()
{
    string s;
    int count = 0;
    int pos;

    while (true)
    {
        count =0;
        cin >> s;
        if (s == "#") break;
        
        
        for(size_t i = 0; i < s.size(); i++)
        {
            if (i==0) {
                pos = position(s[i]);
            }
            else
            {
                if (position(s[i]) == pos)
                {
                    count += 0;
                    pos *= 1;
                }
                else
                {
                    count += 1;
                    pos *= -1;
                } 
            }
        }
        
        cout << count << endl;
    }
    return 0;
}
