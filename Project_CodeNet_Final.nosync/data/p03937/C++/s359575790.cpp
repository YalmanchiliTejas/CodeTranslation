#include <cstdio>
#include <utility>
#include <typeinfo>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int ll;
using namespace std;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;



int main()
{
    int h,w;
    cin >> h >> w;
    int count =0;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            char tmp;
            cin >> tmp;
            if(tmp == '#')
            {
                count++;
            }
        }
    }

    if(count == h+w-1)
    {
        cout <<"Possible"<<endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

   return 0 ;

}
