#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{

    bitset<18> subset;
    
    int n;
    cin >> n;

    int upper = pow(2, n);
    for (int i = 0; i < upper; i++)
    {
        subset = i;
        
        cout << i << ":";        
        for (int j = 0; j < n; j++)
        {
            if (subset[j])
            {
                cout << ' ' <<  j;
            }
        }
        cout << endl;
    }
}
