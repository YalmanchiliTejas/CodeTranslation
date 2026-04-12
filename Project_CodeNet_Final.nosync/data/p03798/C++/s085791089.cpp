#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e5+50;
int poss[4][2]= {1,1,1,2,2,1,2,2};
int b[maxn];
char str[maxn];
char ans[maxn];
int n;
bool flag=0;
bool check()
{
    for(int i=1; i<=n; i++)
    {
        int left=i-1;
        int right=i+1;
        if(i==1)
            left=n;
        if(i==n)
            right=1;
        if(b[i]==1)
        {
            if(str[i]=='o'&&b[left]!=b[right])
            {
                return false;
            }
            else if(str[i]=='x'&&b[left]==b[right])
            {
                return false;
            }
        }
        else
        {
            if(str[i]=='o'&&b[left]==b[right])
                return false;
            else if(str[i]=='x'&&b[left]!=b[right])
                return false;
        }
    }
    return 1;
}
void solve()
{
    for(int i=0; i<4; i++)
    {
        bool flag1=0;
        b[1]=poss[i][0];
        b[2]=poss[i][1];
        for(int j=2; j<=n; j++)
        {
            int k;
            if(b[j]==1)
            {
                if(str[j]=='o')
                {
                    b[j+1]=b[j-1];
                    k=1;
                }
                else
                {
                    if(b[j-1]==1)
                        b[j+1]=2;
                    else
                        b[j+1]=1;
                    k=2;
                }
            }
            else
            {
                if(str[j]=='o')
                {
                    if(b[j-1]==1)
                        b[j+1]=2;
                    else
                    {
                        b[j+1]=1;
                    }
                    k=3;
                }
                else
                {
                    b[j+1]=b[j-1];
                    k=4;
                }
            }
            //cout << b[j] << endl;
            //cout << k << " " << b[j+1]<<endl;

        }
        /*for(int i=1; i<=n; i++)
        {
            printf("%d",b[i]);
        }
        printf("\n");
        cout << i <<endl;*/
        flag1=check();
        if(flag1)
        {
            //cout << 1<< endl;
            for(int i=1;i<=n;i++)
            {
               if(b[i]==1)
               {
                   printf("S");
               }
               else
               {
                   printf("W");
               }
            }
            printf("\n");
            flag=1;
            return ;
        }
    }
}
int main()
{
    cin>>n;
    scanf("%s",str+1);
    solve();
    if(!flag)
        cout << -1 << endl;
    return 0;
}

