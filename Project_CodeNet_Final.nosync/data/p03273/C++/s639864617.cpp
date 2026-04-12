#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
#define INF -99999999 
using namespace std;
 
int main()
{
    int H,W; cin >> H >> W;
    char a[H][W];
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> a[i][j];
        }
        
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if(a[i][j] == '#') break;
            if(j==W-1){
                for (int k = 0; k < W; k++)
                {
                    a[i][k] = '@';
                }
            }
        }
    }
    for (int j = 0; j < W; j++)
    {
        for (int i = 0; i < H; i++)
        {
            if(a[i][j] == '#') break;
            if(i==H-1){
                for (int k = 0; k < H; k++)
                {
                    a[k][j] = '@';
                }
            }
        }
    }
    
    for (int i = 0; i < H; i++)
    {
        int cnt = 0;
        for (int j = 0; j < W; j++)
        {
            if(a[i][j] != '@') cout << a[i][j];
            else cnt++;
        }
        if(cnt != W) cout << endl;
    }

}