#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define ll long long
#define sf1(a); scanf("%d",&a);
#define sf2(a,b); scanf("%d %d",&a, &b);
#define sf3(a,b,c); scanf("%d %d %d",&a, &b,&c);
#define sf4(a,b,c,d); scanf("%d %d %d %d",&a, &b,&c,&d);
#define pf1(a); printf("%d\n",a);
#define pf2(a,b); printf("%d %d\n",a,b);
#define pf3(a,b,c); printf("%d %d %d\n",a,b,c);
#define pf4(a,b,c,d); printf("%d %d %d %d\n",a,b,c,d);

using namespace std;

int main()
{
    int h,w;
    sf2(h,w);
    char a[h][w],b[h][w],c[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a[i][j];
        }
    }

    int r=0,cl=0;

    for(int i=0;i<h;i++)
    {
        int f=0;
        for(int j=0;j<w;j++)
        {
            if(a[i][j]!='.')
            {
                f = 1;
                break;
            }
        }
        if(f)
        {
            for(int j=0;j<w;j++)
            {
                b[r][j]=a[i][j];
            }
            r++;
        }
    }

    int k=0;
    for(int i=0;i<w;i++)
    {
        int f=0;
        for(int j=0;j<r;j++)
        {
            if(b[j][i]!='.')
            {
                f = 1;
                break;
            }
        }
        if(f)
        {
            for(int j=0;j<r;j++)
            {
                c[j][cl]=b[j][i];
            }
            cl++;
        }
    }

    if(cl==1)
    {
        for(int i=0;i<r;i++)
        {
            cout<<c[i][0];
        }
        cout<<endl;
        return 0;
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<cl;j++)
        {
            cout<<c[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
