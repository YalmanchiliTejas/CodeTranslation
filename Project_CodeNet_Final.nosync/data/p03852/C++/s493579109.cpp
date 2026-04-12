#include <iostream>
#include <vector>
using namespace std;
int main()
{
    char c;
    cin >> c;
    vector<char> v{'a', 'e', 'i', 'o', 'u'};
    for (auto x : v)
    {
        if (c == x)
        {
            puts("vowel");
            return 0;
        }
    }
    puts("consonant");
}