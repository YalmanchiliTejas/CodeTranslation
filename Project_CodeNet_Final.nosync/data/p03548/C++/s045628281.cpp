#include <iostream>

using namespace std;

int main()
{
    int x,y,len;
    cin >> len >> x >>y;
    int sum;
    if(len%(x+y)==y)
    {
        cout << len/(x+y);
    }
    else
        cout << len/(x+y)-1;
    cout << endl;
}
