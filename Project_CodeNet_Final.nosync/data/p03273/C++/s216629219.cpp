#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));

    for (int count = 0; count < H; count++)
    {
        for (int index = 0; index < W; index++)
        {
            cin >> A.at(count).at(index);
        }
    }

    bool flag = true, whiteFlag = false;
    while (flag)
    {
        flag = false;
        for (int count = 0; count < H; count++)
        {
            if (A.at(count).at(0) != '#')
            {
                whiteFlag = true;
                for (int index = 0; index < W; index++)
                {
                    if (A.at(count).at(index) == '#')
                    {
                        whiteFlag = false;
                        break;
                    }
                }
                if (whiteFlag)
                {
                    for (int index = 0; index < W; index++)
                    {
                        if (A.at(count).at(index) == '.')
                        {
                            A.at(count).at(index) = ' ';
                            flag = true;
                        }
                    }
                }
            }
        }
        for (int count = 0; count < W; count++)
        {
            if (A.at(0).at(count) != '#')
            {
                whiteFlag = true;
                for (int index = 0; index < H; index++)
                {
                    if (A.at(index).at(count) == '#')
                    {
                        whiteFlag = false;
                        break;
                    }
                }
                if (whiteFlag)
                {
                    flag = false;
                    for (int index = 0; index < H; index++)
                    {
                        if (A.at(index).at(count) == '.')
                        {
                            A.at(index).at(count) = ' ';
                            flag = true;
                        }
                    }
                }
            }
        }
    }

    bool displayFlag = false;
    for (int count = 0; count < H; count++)
    {
        for (int index = 0; index < W; index++)
        {
            if (A.at(count).at(index) != ' ')
            {
                displayFlag = true;
                cout << A.at(count).at(index);
            }
            if (displayFlag && index == W - 1)
            {
                cout << endl;
            }
        }
        displayFlag = false;
    }
}