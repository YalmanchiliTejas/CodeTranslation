#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<limits>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int64_t n;
    cin>>n;
    int x,m;
    cin>>x>>m;
    int64_t a=x;
    vector<int> c(m,0);
    int64_t d=x;
    c[x]=1;
    queue<int> e;
    e.push(x);
    int f=-1;
    int g=-1;
    int h=0;
    for (int i = 1; i < n; i++)
    {
        d=(d*d)%m;
        a+=d;

        if (d==0)
        {
            break;
        }else if (c[d]==1)
        {
            e.push(d);
            while(f!=d){
                f=e.front();
                e.pop();
            }
            g=i;
            break;
            
        }else
        {
            c[d]=1;
            e.push(d);
        }  
    }

    int64_t aa,ab;
    int64_t ac=0;

    if (g==-1)
    {
        cout<<a<<endl;
    }else
    {
        aa=(n-g-1)/e.size();
        ab=(n-g-1)%e.size();
        while (!e.empty())
        {
            ac+=e.front();
            h++;
            e.pop();
            if (h==ab)
            {
                a+=ac;
            }
        }
        a+=aa*ac;
        cout<<a<<endl;
    }


    


    return 0;
}