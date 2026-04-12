#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int w, h;
    cin >> h >> w;
    string mat[h], ans[h];
    for(int i = 0; i < h; i++)
    {
        cin >> mat[i];
        ans[i] = mat[i];
    }
    for(int i = 0; i < h; i++)
    {
        int cnt = 0;
        for(int j = 0; j < w; j++)
        {
            if(mat[i][j] == '.')
                cnt++;
        }
        if(cnt == w)
        {
            fill(ans[i].begin(), ans[i].end(), 'x');
        }
    }
    for(int i = 0; i < w; i++)
    {
        int cnt = 0;
        for(int j = 0; j < h; j++)
        {
            if(mat[j][i] == '.')
                cnt++;
        }
        if(cnt == h)
        {
            for(int j = 0; j < h; j++)
                ans[j][i] = 'x';
        }
    }
    for(int i = 0; i < h; i++)
    {
        bool flag = false;
        for(int j = 0; j < w; j++)
        {
            if(ans[i][j] != 'x')
            {
                cout << ans[i][j];
                flag = true;
            }
        }
        if(flag)
            cout << endl;
    }
//    main();
}

