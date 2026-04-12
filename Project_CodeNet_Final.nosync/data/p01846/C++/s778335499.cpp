#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i < (int)(b);++i)

int main(void) {
    while (true) {
        string S;
        cin >> S;
        if(S == "#")
        {
            return 0;
        }
        int sx,sy;
        int tx, ty;
        cin >> sx >> sy >> tx >> ty;
        sx--; sy--; tx--; ty--;

        int H = 1;
        rep(i, S.size())
        {
            if(S[i] == '/')
            {
                H++;
            }
        }

        int W = 0;
        rep(i, S.size())
        {
            if(S[i] == '/')
            {
                break;
            }
            else if(S[i]=='b')
            {
                W++;
            }
            else
            {
                W +=(S[i]-'0');
            }

        }

        int M[H][W];
        memset(M, 0, sizeof(M));
        int y = 0;
        int x = 0;
        rep(i, S.size())
        {
            if(S[i] == '/')
            {
                y++;
                x = 0;
            }
            else if(S[i]=='b')
            {
                M[y][x] = 1;
                x++;
            }
            else{
                int t  = (S[i] - '0');
                x += t;
                
            }
    
        }
        M[sx][sy] = 0;
        M[tx][ty] = 1;

        rep(i, H)
        {
            int cnt = 0;
            rep(j, W)
            {
                if(M[i][j] == 1)
                {
                    if(cnt > 0)
                    {
                        cout << cnt;
                        cnt = 0;
                    }
                    cout << "b";
                }
                else
                {
                    cnt++;
                }

            }
            if(cnt > 0)
            {
                cout << cnt;
            }
            if(i != H - 1)cout << "/";
        }
        cout << endl;
    }

}
