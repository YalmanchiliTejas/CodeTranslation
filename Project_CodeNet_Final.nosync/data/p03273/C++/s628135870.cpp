#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    int h, w;
    cin >> h >> w;
    char arr[100 + 5][100 + 5];
    bool vis[100 + 5][100 + 5] = {};
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> arr[i][j];
    for(int i = 0; i < h; i++){
        bool hash = false;
        for(int j = 0; j < w; j++)
            if(arr[i][j] == '#')
                hash = true;
        if(!hash)
            for(int j = 0; j < w; j++)
                vis[i][j] = true;
    }
    for(int j = 0; j < w; j++){
        bool hash = false;
        for(int i = 0; i < h; i++)
            if(arr[i][j] == '#')
                hash = true;
        if(!hash)
            for(int i = 0; i < h; i++)
                vis[i][j] = true;
    }
    for(int i = 0; i < h; i++){
        bool endll = false;
        for(int j = 0; j < w; j++)
            if(vis[i][j] == false)
                endll = true;
        if(endll == false)
            continue;
        for(int j = 0; j < w; j++)
            if(vis[i][j] == false)
                cout << arr[i][j];
        cout << endl;
    }
    return 0;
}