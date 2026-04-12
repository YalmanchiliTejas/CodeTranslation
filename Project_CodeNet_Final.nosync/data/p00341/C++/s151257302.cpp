#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const int kNumSide = 12;
    vector<int> side(kNumSide);

    for(int i = 0; i < kNumSide; i++)
    {
        cin >> side[i];
    }
    sort(side.begin(), side.end());

    bool canMakeCuboid = true;
    for(int i = 1; i < 4; i++)
    {
        if(side[0] != side[i])
        {
            canMakeCuboid = false;
            break;
        }
        if(side[4] != side[4+i])
        {
            canMakeCuboid = false;
            break;
        }
        if(side[8] != side[8+i])
        {
            canMakeCuboid = false;
            break;
        }
    }

    if(canMakeCuboid)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}