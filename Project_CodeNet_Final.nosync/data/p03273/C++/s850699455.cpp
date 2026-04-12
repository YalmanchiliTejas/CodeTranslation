#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int h,w;
    cin>>h>>w;
    vector<string> a(h);
    bool wskip[100],hskip[100];
    
    for(int i = 0; i < 100; i++)
    {
        wskip[i]=true;
        hskip[i]=true;
    }
    
    for(int i = 0; i < h; i++)
    {
        cin>>a[i];
    }
    
    
    for(int hh = 0; hh < h; hh++)
    {
        for(int ww = 0; ww < w; ww++)
        {
            if(a[hh][ww]=='#')
            {
                hskip[hh]=false;
                break;
            }
        }
    }
    
    for(int ww = 0; ww < w; ww++)
    {
        
        for(int hh = 0; hh < h; hh++)
        {
            if(a[hh][ww]=='#')
            {
                wskip[ww]=false;
                break;
            }
        }        
    }
    
    
    for(int hh = 0; hh < h; hh++)
    {
        if(hskip[hh]==false)
        {
            
            for(int ww = 0; ww < w; ww++)
            {
                if(wskip[ww]==false)
                {
                    cout<<a[hh][ww];
                }
            }
            cout<<endl;
        }
        
    }
    

    return 0;
}