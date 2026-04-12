#include <iostream>

using namespace std;

int main()
{
    int number = 0;

    for(int i = 0; i < 3; i++)
    {
        int tmp;
        cin >> tmp;

        number *= 10;
        number += tmp;
    }
    
    if(number % 4)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}
