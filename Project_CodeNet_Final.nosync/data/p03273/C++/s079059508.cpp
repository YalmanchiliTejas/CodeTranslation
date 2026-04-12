#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

const int mod = 1000000007;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> vec(h);
    for (int i = 0; i < h; i++)
    {
        cin >> vec[i];
    }
    
    vector<bool> x(h, false);
    vector<bool> y(w, false);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (vec[i][j] == '#')
            {
                x[i] = true;
                y[j] = true;
            }
        }
    }
    
    for (int i = 0; i < h; i++)
    {
        if (x[i])
        {
            for (int j = 0; j < w; j++)
            {
                if (y[j])
                {
                    cout << vec[i][j];
                }
            }
            cout << endl;
        }
    }
}