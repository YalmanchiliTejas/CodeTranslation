#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

/*ifstream fin ("contest.in");
ofstream fout ("contest.out");*/

char c;
int main()
{
    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')cout << "vowel";
    else cout << "consonant";
    return 0;
}
