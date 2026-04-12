#include <bits/stdc++.h>
//#include <map>
//#include <set>
//#include <list>
//#include <cmath>
//#include <ctime>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <string>
//#include <bitset>
//#include <cstdio>
//#include <limits>
//#include <vector>
//#include <climits>
//#include <cstring>
//#include <cstdlib>
//#include <fstream>
//#include <numeric>
//#include <sstream>
//#include <iomanip>
//#include <iostream>
//#include <algorithm>
//#include <unordered_map>

using namespace std;

#define file freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define PI 3.141592653589793238462643383279502884
#define MAX 1000100
#define mod 1000000007
#define EPS 1E-9
#define int long long
#define endl "\n"

int fix(int cur, int m)
{
    return ((cur%m) + m) % m;
}

int fast_power(int x, int y,int m)
{
    if (y == 0)
        return 1;
    int temp = fast_power(x, y / 2, m) ;
    temp = (temp*temp)% m;
    if (y % 2 != 0)
        temp = (temp*x)% m;
    return temp;

}

string s;
int k;
vector<int>v;

void conv()
{
    for(int i=0;i<s.size();i++)
        v.push_back(s[i]-'0');
}
int DP[110][110][4];
int solve(int idx,int digits,bool Less)
{
    if(digits>k)
        return 0;
    if(idx==v.size())
    {
        if(digits==k)
            return 1;
        return 0;
    }
    int &ret=DP[idx][digits][Less];
    if(ret!=-1)
        return ret;
    int limit;
    if(!Less)
        limit=v[idx];
    else
        limit=9;
    int cnt=0;
    for(int i=0;i<=limit;i++)
    {
        int dig=digits;
        int LESS=Less;
        if(i!=0)
            dig++;
        if(i<limit)
            LESS=1;
        cnt+=solve(idx+1,dig,LESS);
    }
    return ret=cnt;
}


int32_t main()
{
    //freopen("D:/Important Files/Cocktail/SOLVE/TestLib/testcases/input/input11.txt", "r", stdin);
    //freopen("D:/Important Files/Cocktail/SOLVE/TestLib/testcases/output/output11.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    memset(DP,-1,sizeof(DP));
    cin >> s >> k;
    conv();
    cout << solve(0,0,0);

    return 0;
}
