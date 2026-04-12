#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<char>> transpose(vector<vector<char>> A)
{
    int l = A.size(), m = A.at(0).size();

    vector<vector<char>> ret(m, vector<char>(l));

    rep(i, m)
    {
        rep(j, l)
        {
            ret.at(i).at(j) = A.at(j).at(i);
        }
    }

    return ret;
}

void print_matrix(vector<vector<char>> A)
{
    for (vector<char> row : A)
    {
        for (char ele : row)
        {
            cout << ele;
        }
        cout << endl;
    }
}

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char>> A(H, vector<char>(W));

    rep(i, H)
    {
        rep(j, W)
        {
            cin >> A.at(i).at(j);
        }
    }

    vector<vector<char>> A1;

    // compress row
    rep(i, H)
    {
        bool canCompress = true;

        rep(j, W)
        {
            if (A.at(i).at(j) == '#')
            {
                canCompress = false;
            }
        }

        if (!canCompress)
        {
            A1.push_back(A.at(i));
        }
    }

    // transpose and update sizes
    A1 = transpose(A1);
    H = A1.size();
    W = A1.at(0).size();

    vector<vector<char>> A2;

    // compress column
    rep(i, H)
    {
        bool canCompress = true;

        rep(j, W)
        {
            if (A1.at(i).at(j) == '#')
            {
                canCompress = false;
            }
        }

        if (!canCompress)
        {
            A2.push_back(A1.at(i));
        }
    }

    A2 = transpose(A2);

    print_matrix(A2);
}