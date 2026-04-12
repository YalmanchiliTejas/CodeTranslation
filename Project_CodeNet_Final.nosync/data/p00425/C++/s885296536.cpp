#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdint.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define RREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define FOR(i, l, r) for(int i = l; i < r; i++)
#define RFOR(i, l,r) for(int i= (l)-1; i>= (r) ; i--)

int now = 1;
int dots[2] = {2, 3}; // 0 : S , 1 : E

void rotate(char c)
{
    int n_now = now, n_dots[] = {dots[0], dots[1]};

    switch(c)
    {
        case 'N':
            n_now = dots[0];
            n_dots[0] = 7 - now;
            break;
        case 'W':
            n_now = dots[1];
            n_dots[1] = 7 - now;
            break;
        case 'E':
            n_now = 7 - dots[1];
            n_dots[1] = now;
            break;
        case 'S':
            n_now = 7 - dots[0];
            n_dots[0] = now;
            break;
        case 'L':
            n_dots[0] = 7 - dots[1];
            n_dots[1] = dots[0];
            break;
        case 'R':
            n_dots[1] = 7 - dots[0];
            n_dots[0] = dots[1];
            break;
    }
    now = n_now;
    dots[0] = n_dots[0];
    dots[1] = n_dots[1];
}

int solve(string s, int n)
{
    now = 1;
    dots[0] = 2;
    dots[1] = 3;
    int sum = now;
    REP(i, n)
    {
        rotate(s[i]);
        sum += now;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        string s;
        REP(i, n)
        {
            string tmp;
            cin >> tmp;
            s += tmp[0];
        }
        cout << solve(s, n) << endl;
    }
}