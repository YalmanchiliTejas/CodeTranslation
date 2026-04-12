#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int H,W;
    cin >> H>>W;
    
    vector<vector<char>> a(H,vector<char>(W));
    
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cin >> a[i][j];
        }
    }
    
    vector<bool> h(H),w(W);
    
    for(int i=0;i<H;i++)
    {
        bool del = true;
        
        for(int j=0;j<W;j++)
        {
            if(a[i][j] == '#')
            {
                del = false;
                break;
            }
        }
        
        if(del)
        {
            h[i] = false;
        }
        else
        {
            h[i] = true;
        }
    }
    
    for(int i=0;i<W;i++)
    {
        bool del = true;
        
        for(int j=0;j<H;j++)
        {
            if(a[j][i] == '#')
            {
                del = false;
                break;
            }
        }
        
        if(del)
        {
            w[i] = false;
        }
        else
        {
            w[i] = true;
        }
    }
    
    for(int i=0;i<H;i++)
    {
        if(h[i])
        {
            for(int j=0;j<W;j++)
            {
                if(w[j])
                {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    
    //cout << c << endl;
    return 0;
}