#include <iostream>
#include <algorithm>
#include <vector>

using ull = unsigned long long int;

bool rows[550], cols[550];
ull rowval[550], colval[550];
ull ans[550][550];
bool placed0row[550], placed1row[550], placed0col[550], placed1col[550];
bool pusheda0row[550], pushedor1row[550], pusheda0col[550], pushedor1col[550];

bool getbit(ull nr, int pos)
{
    return (nr & ((ull)1 << pos)) > 0;
}

bool solve(int pos, int n)
{
    std::vector<int> a0row, a0col, or1row, or1col;
    for (int i = 0; i < n; ++i)
    {
        placed0row[i] = placed1row[i] = placed0col[i] = placed1col[i] = 0;
        pusheda0row[i] = pusheda0col[i] = pushedor1row[i] = pushedor1col[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int bitrow = getbit(rowval[i], pos), bitcol = getbit(colval[j], pos);
            if (bitrow == 1 && rows[i] == 0 && bitcol == 0 && cols[j] == 1)
                return 0;
            if (bitrow == 0 && rows[i] == 1 && bitcol == 1 && cols[j] == 0)
                return 0;

            //AND0
            if (bitrow == 0 && rows[i] == 0 && !pusheda0row[i])
            {
                a0row.push_back(i);
                pusheda0row[i] = true;
            }
            //OR1
            if (bitrow == 1 && rows[i] == 1 && !pushedor1row[i])
            {
                or1row.push_back(i);
                pushedor1row[i] = true;
            }
            if (bitcol == 0 && cols[j] == 0 && !pusheda0col[j])
            {
                a0col.push_back(j);
                pusheda0col[j] = true;
            }
            if (bitcol == 1 && cols[j] == 1 && !pushedor1col[j])
            {
                or1col.push_back(j);
                pushedor1col[j] = true;
            }

            if (bitrow == 0 && rows[i] == 0 && bitcol == 1 && cols[j] == 1)
                continue;
            if (bitrow == 1 && rows[i] == 1 && bitcol == 0 && cols[j] == 0)
                continue;


            if ((bitrow == 1 && rows[i] == 0) || (bitcol == 1 && cols[j] == 0))
            {
                ans[i][j] += ((ull)1 << pos);
                placed1row[i] = 1;
                placed1col[j] = 1;
            }
            else if ((bitrow == 0 && rows[i] == 1) || (bitcol == 0 && cols[j] == 1))
            {
                placed0row[i] = 1;
                placed0col[j] = 1;
            }
            else if (bitrow == 0 && rows[i] == 0)
            {
                placed0row[i] = 1;
                placed0col[j] = 1;
            }
            else if (bitrow == 1 && rows[i] == 1)
            {
                ans[i][j] += ((ull)1 << pos);
                placed1row[i] = 1;
                placed1col[j] = 1;
            }
        }
    }

    bool flag = true;
    //row A0 column O1
    for (int i : a0row)
    {
        for (int j : or1col)
        {
            if (placed0row[i] == true)
            {
                ans[i][j] += ((ull)1 << pos);
                placed1row[i] = 1;
                placed1col[j] = 1;
            }
            else if (placed1col[j] == true)
            {
                placed0row[i] = 1;
                placed0col[j] = 1;
            }
            else
            {
                if (flag)
                {
                    placed0row[i] = 1;
                    placed0col[j] = 1;
                    flag = false;
                }
                else
                {
                    ans[i][j] += ((ull)1 << pos);
                    placed1row[i] = 1;
                    placed1col[j] = 1;
                }
            }
        }
    }

    flag = true;
    //row OR1 column A0
    for (int i : or1row)
    {
        for (int j : a0col)
        {
            if (placed1row[i])
            {
                placed0row[i] = true;
                placed0col[j] = true;
            }
            else if (placed0col[j])
            {
                ans[i][j] += ((ull)1 << pos);
                placed1row[i] = true;
                placed1col[j] = true;
            }
            else
            {
                if (flag)
                {
                    placed0row[i] = 1;
                    placed0col[j] = 1;
                    flag = false;
                }
                else
                {
                    ans[i][j] += ((ull)1 << pos);
                    placed1row[i] = 1;
                    placed1col[j] = 1;
                }
            }
        }
    }

    for (int i : a0row)
    {
        if (!placed0row[i]) return false;
    }

    for (int j : or1col)
    {
        if (!placed1col[j]) return false;
    }

    //row OR1 column A0
    for (int i : or1row)
    {
        if (!placed1row[i]) return false;
    }

    for (int j : a0col)
    {
        if (!placed0col[j]) return false;
    }

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> rows[i];
    for (int i = 0; i < n; ++i)
        std::cin >> cols[i];
    for (int i = 0; i < n; ++i)
        std::cin >> rowval[i];
    for (int i = 0; i < n; ++i)
        std::cin >> colval[i];

    for (int i = 0; i < 64; ++i)
    {
        if (!solve(i, n))
        {
            std::cout << -1;
            return 0;
        }

    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cout << ans[i][j] << " ";
        std::cout << "\n";
    }
}
