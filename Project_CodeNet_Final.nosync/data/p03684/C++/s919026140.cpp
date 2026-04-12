#include<iostream>
#include<string>
#include<algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef int status;
typedef long long LL;
const int INF = int(1e9);
const int MAX = 100005;

struct S
{
    int x,wei;
}A[MAX],B[MAX];

struct Bian
{
    int x,y;
    int len;
}biao[MAX*10];
int num = 0;

bool cmp(S a,S b)
{
    return a.x<b.x;
}

bool cmp1(Bian a,Bian b)
{
    return a.len<b.len;
}

int N;

int visit[MAX] = {0};

int Find(int x)
{
    if(visit[x]==x)
        return x;
    else
        return visit[x] = Find(visit[x]);
}

int mix(int x,int y)
{
    int Tx = Find(x);
    int Ty = Find(y);
    if(Tx!=Ty)
    {
        visit[Tx] = Ty;
        return 1;
    }
    return 0;

}


int main()
{
    cin>>N;
    for(int i = 1;i<=N;i++)
    {
        A[i].wei = B[i].wei = i;
        scanf("%d %d",&A[i].x,&B[i].x);
    }
    sort(A+1,A+1+N,cmp);sort(B+1,B+1+N,cmp);
    for(int i = 1;i <N;i++)
    {
        biao[num].x = A[i].wei;
        biao[num].y = A[i+1].wei;
        biao[num++].len = A[i+1].x - A[i].x;
        biao[num].x = B[i].wei;
        biao[num].y = B[i+1].wei;
        biao[num++].len = B[i+1].x - B[i].x;
    }
    sort(biao,biao+num,cmp1);

    LL sum = 0;
    for(int i = 0;i<=N;i++)
        visit[i] = i;
    for(int i = 0;i<num;i++)
    {
        Bian temp = biao[i];
        if(mix(temp.x,temp.y)==1)
        {
            sum += temp.len;
        }
    }

    cout<<sum<<endl;

    return 0;
}
