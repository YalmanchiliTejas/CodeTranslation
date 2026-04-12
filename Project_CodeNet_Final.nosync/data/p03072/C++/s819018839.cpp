#include <iostream>

using namespace std;

int main()
{
    int n, h, cnt=0, top=0;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> h;

        if(top <= h)
        {
            top = h;

            cnt++;
        }
    }

    cout << cnt << endl;


    return 0;
}
