#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<char> s;
    for(int i = 0; i < 3; i++)
    {
        char t;
        cin >> t;
        s.insert(t);
    }
    if((int)s.size() <= 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}