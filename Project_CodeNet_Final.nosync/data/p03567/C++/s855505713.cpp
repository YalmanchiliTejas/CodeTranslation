#include <iostream>
using namespace std;
char Str[7];
bool Read()
{
    cin.getline(Str + 1, 7);
    for(int i = 1; Str[i] != 0; i++)
    {
        if(Str[i + 1] == 0)
            return 0;
        if(Str[i] == 'A' && Str[i + 1] == 'C')
            return 1;
    }
    return 0;
}

int main()
{
    if(Read())
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
