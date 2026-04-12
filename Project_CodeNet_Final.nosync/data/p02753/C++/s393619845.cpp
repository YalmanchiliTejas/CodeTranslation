#include <iostream>

using namespace std;

int main()
{
    char S[3];
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        scanf("%c", &S[i]);
        if (S[i] == 'A')
            count++;
    }

    count == 1 || count == 2 ? cout << "Yes" : cout << "No";
    cout << "\n";
}