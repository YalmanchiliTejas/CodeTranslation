#include <bits/stdc++.h>

#define MAX_A 10
#define MAX_B 10
#define MAX_C 100

#define xx first
#define yy second

#define MAX_CATE 100

using namespace std;

int d[MAX_A + 1][MAX_B + 1];

int cate[MAX_C + 1][MAX_C + 1][MAX_C + 1];

vector <pair<pair<int, int>, int>> g[MAX_A + 1][MAX_B + 1];
vector <pair<int, int>> care[MAX_C + 1][MAX_C + 1][MAX_C + 1];

bool luat[MAX_A + 1][MAX_B + 1];

struct rezul
{
    int a, b, c;
};

int rez;
rezul rz[MAX_CATE + 1];

int A, B;

int main()
{
    cin >> A >> B;

    int i, j;
    for(i = 1; i <= A; i ++)
    {
        for(j = 1; j <= B; j ++)
            cin >> d[i][j];
    }

    int a, b, c, x, y;
    for(a = 0; a <= 100; a ++)
    {
        for(b = 0; b <= 100; b ++)
        {
            for(c = 0; c <= 100; c ++)
            {
                int ok = 1;
                int oke = 0;
                for(x = 1; x <= A && ok; x ++)
                {
                    for(y = 1; y <= B && ok; y ++)
                    {
                        ok = ok && (a * x + b * y + c >= d[x][y]);
                        oke = oke || (a * x + b * y + c == d[x][y]);
                    }
                }

                if(ok && oke)
                {
                    for(x = 1; x <= A; x ++)
                    {
                        for(y = 1; y <= B; y ++)
                        {
                            if(a * x + b * y + c == d[x][y])
                            {
                                cate[a][b][c] ++;
                                care[a][b][c].push_back({x, y});
                                g[x][y].push_back({{a, b}, c});
                            }
                        }
                    }
                }
            }
        }
    }

    int sum = 0;
    for(x = 1; x <= A; x ++)
    {
        for(y = 1; y <= B; y ++)
        {
            if(luat[x][y] == 0)
            {
                luat[x][y] = 1;
                if(g[x][y].size() == 0)
                {
                    cout << "Impossible\n";
                    return 0;
                }

                int a = g[x][y][0].xx.xx;
                int b = g[x][y][0].xx.yy;
                int c = g[x][y][0].yy;

                rz[++ rez] = {a, b, c};
                sum += a + b + 1;//(c > 0);

                for(auto u : care[a][b][c])
                    luat[u.xx][u.yy] = 1;
            }
        }
    }

    cout << "Possible\n";
    cout << "300 " << sum << "\n";
    assert(sum <= 300);

    int k = 2;
    int ant = 1;
    for(i = 1; i <= rez; i ++)
    {
        int a = rz[i].a;
        int b = rz[i].b;
        int c = rz[i].c;

        ant = 1;
        for(j = 1; j <= a; j ++)
        {
            cout << ant << " " << k << " X\n";
            ant = k;
            k ++;
        }


        for(j = 1; j <= b; j ++)
        {
            cout << ant << " " << k << " Y\n";
            ant = k;
            k ++;
        }

        cout << ant << " 300 " << c << "\n";
    }


    cout << "1 300" << "\n";

    return 0;
}
