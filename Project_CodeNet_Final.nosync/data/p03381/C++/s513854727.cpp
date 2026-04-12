#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef struct node
{
    int id;
    int val;
} num;
num B[200005];
int A[200005],id[200005];
bool cmp(node a,node b)
{
    return a.val < b.val;
}
int main(void)
{
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&A[i]);
        B[i].id = i;
        B[i].val = A[i];
    }
    sort(B,B+N,cmp);
    int midl = B[N/2].val;
    int midr = B[N/2 - 1].val;
    for(int i = 0;i < N;i++)
    {
        id[B[i].id] = i;
    }
    for(int i = 0;i < N;i++)
    {
        if(id[i] <= N/2-1)
            printf("%d\n",midl);
        else printf("%d\n",midr);
    }
    return 0;
}
