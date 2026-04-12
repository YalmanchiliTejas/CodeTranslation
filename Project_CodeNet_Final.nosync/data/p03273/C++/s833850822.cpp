#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    
    cin >> H >> W;

    vector<string> vec(H);
    for(int i = 0; i < H; i++) cin >> vec.at(i);


    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {    
            if(vec.at(i).at(j) != '.')
            {
                break;
            }
            if(j == W - 1)
            {
                for(int k = 0; k < W; k++) vec.at(i).at(k) = '_';
            }
        }
    }

    for(int i = 0; i < W; i++)
    {
        for(int j = 0; j < H; j++)
        {
            if(vec.at(j).at(i) != '.' && vec.at(j).at(i) != '_')
            {
               break;
            }
            if(j == H - 1)
            {
                //cout << "yes" << endl;
                for(int k = 0; k < H; k++) vec.at(k).at(i) = '_';
            }
        }
    }

    bool flag = false;

    for(int i = 0; i < H; i++)
    {
        flag = false;
        for(int j = 0; j < W; j++)
        {
            if(vec.at(i).at(j) != '_')
            {
                cout << vec.at(i).at(j);
            }

            for(int k = 0; k < W; k++)
            {
                if(vec.at(i).at(k) == '#') flag = true;
            }

        }
        if(flag) cout << endl;
    }

    return 0;
}