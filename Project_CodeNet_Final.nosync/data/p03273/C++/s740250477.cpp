#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <fstream>
#include <functional>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 200001
//#define NCONS 100001
//#define NCONS 1001
//#define NCONS 101
#define MCONS 2001
#define LIMIT 1000000000
#define TRUE 1
#define FALSE 0
#define toRadian(degree) ((degree) * (M_PI / 180.))
#define toDegree(radian) ((radian) * (180. / M_PI))
using namespace std;
struct Point{int x; int y;};
struct PPoint{Point x; Point y;};
ll gcd(ll a, ll b) { if(a < b) swap(a, b); if(b <= 0) return a; return gcd(b, a % b); }

int H, W;
bool visited[101];
bool check(string str)
{
    for(int i = 0; i < (int)str.size(); i++)
        if(str[i] == '#')
            return true;
    return false;
}
int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> H >> W;
    vector<string> grid;
    for(int i = 0; i < H; i++)
    {
        string temp; cin >> temp;
        if(check(temp))
            grid.push_back(temp);
    }
    
    for(int i = 0; i < W; i++)
    {
        bool flag = false;
        for(int j = 0; j < (int)grid.size(); j++)
        {
            if(grid[j][i] == '#')
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
            visited[i] = true;
    }
    
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(visited[j]) continue;
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
