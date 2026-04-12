/** coder Mohammad Al-Hussein *_^ */
#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define mp make_pair
#define All(v) v.begin(),v.end()
#define mod  1000000007
#define write freopen("output.txt","w",stdout)
#define read freopen("test (1).txt","r",stdin)
#define FIO std::ios_base::sync_with_stdio(false);
using namespace std;
char a[10][10];
bool vis[10][10];
int H,W;
void flood(int i,int j)
{
    if(i >= H || j >= W) return ;

    a[i][j] = '.';
    if(i == H-1 && j == W-1)
        return ;
    if(a[i][j+1] == '#')
        flood(i,j+1);
    else if(a[i+1][j] == '#')
        flood(i+1,j);
}
int main()
{
    cin >> H >> W;
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            cin >> a[i][j];
    flood(0,0);
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            if(a[i][j] == '#')
                return cout << "Impossible\n",0;
    cout << "Possible\n";

    return 0;
}
