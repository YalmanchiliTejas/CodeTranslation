#include<iostream>
#include<bits/stdc++.h>
#define pq priority_queue
#define Pi acos(-1.0)
using namespace std;
#define INFF 10000000007
#define MOD 1000000007
char s[100005];
int len;
bool life[100005],flag=0;
bool ok(bool x,bool y)
{
    life[0]=x;
    life[1]=y;
    for(int i=1;i<len;i++)
    {
        if(s[i]=='o')
        {
            if(life[i])
                life[i+1]=!life[i-1];
            else
                life[i+1]=life[i-1];
        }
        else
        {
            if(life[i]==0)
                life[i+1]=!life[i-1];
            else
                life[i+1]=life[i-1];
        }
    }
    if((s[0]=='o' && !life[0]) || (s[0]!='o' && life[0]))
    {
        if(life[1]==life[len])
        {
            if((s[len]=='o' && !life[len]) || (s[len]!='o' && life[len]))
                return life[0]==life[len-1];
            else
                return life[0]!=life[len-1];
        }
        else
            return 0;
    }
    else
    {
        if(life[1]!=life[len])
        {
            if((s[len]=='o' && !life[len]) || (s[len]!='o' && life[len]))
                return life[0]==life[len-1];
            else
                return life[0]!=life[len-1];
        }
        else
            return 0;
    }
}
int main()
{
    cin>>len;
    len--;
    scanf("%s",s);
    if(ok(0,0))
        flag=1;
    else
    {
        if(ok(0,1))
            flag=1;
        else
        {
            if(ok(1,0))
                flag=1;
            else
                flag=ok(1,1);
        }
    }
    if(!flag)
        printf("-1\n");
    else
    {
        for(int i=0;i<=len;i++)
        {
            if(life[i])
                printf("W");
            else
                printf("S");
        }
        printf("\n");
    }
    return 0;
}
