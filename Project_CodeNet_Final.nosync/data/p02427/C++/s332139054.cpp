#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;

// #define DEBUG

class Unionfind
{
    vector<int> p;

public:
    Unionfind(int n);
    int find(int x);
    void unite(int x, int y);
    bool match(int x, int y);
};

Unionfind::Unionfind(int n)
{
    for (int i = 0; i < n; i++)
    {
        p.push_back(i);
    }
}

int Unionfind::find(int x)
{
    while (p[x] != x)
    {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}

bool Unionfind::match(int x, int y)
{
    return (find(x) == find(y)) ? true : false;
}

void Unionfind::unite(int x, int y)
{
    x = Unionfind::find(x);
    y = Unionfind::find(y);
    if (x != y)
    {
        p[x] = y;
    }
}

int main()
{
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif
    int n, x, t;
cin >> n;
    for (int i = 0; i < pow(2, n); i++){
        cout << i << ":";
        x = i;
        t = 0;
        while (x > 0){
            if (x % 2 == 1)
                cout << " " << t;
            x /= 2;
            t++;
        }
        cout << endl;
    }

    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)
