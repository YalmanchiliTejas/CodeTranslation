#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
        int a = 0, b = 0;
        string s1;
        cin >> s1; 
        for (auto c : s1)
                if (c == 'A')
                        a++;
                else
                        b++;
        if (a && b)
                cout << "Yes";
        else 
                cout <<"No";
        cout << endl;
        return 0;
}