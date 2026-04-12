#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)
#define all(n) n.begin(),n.end()

const int TAN = 0, FUKU = 1;

int way, bill;
double rate = 0;

int main()
{
    int m, nowm, money, year, n, maxmoney, risi;
    cin >> m;
    while(m--)
    {
        cin >> money >> year >> n;
        maxmoney = money;

        REP(n)
        {
            nowm = money, risi = 0;
            cin >> way >> rate >> bill;
            if(way == TAN)
            {
                rep(j, year)
                {
                    risi += rate * nowm;
                    nowm -= bill;
                }
                nowm = nowm + risi;
            }
            if(way == FUKU)
            {
                rep(j, year)
                {
                    nowm += rate * nowm;
                    nowm -= bill;
                }
            }
            maxmoney = max(maxmoney, nowm);
        }
        cout << maxmoney << endl;
    }

    return 0;
}