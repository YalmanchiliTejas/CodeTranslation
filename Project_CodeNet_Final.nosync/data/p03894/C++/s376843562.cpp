#include<bits/stdc++.h>
using namespace std;

int N,Q;
int fid[100010];
bool in[100010];

int main()
{
    scanf("%d%d",&N,&Q);
    in[1] = in[2] = true;
    int now = 1;
    for(int i = 1; i <= N; i++)fid[i] = i;
    for(int i = 0; i < Q; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        swap(fid[a],fid[b]);
        if(now == a)now = b;
        else if(now == b)now = a;
        in[fid[now + 1]] = in[fid[now - 1]] = true;
    }

    int ans = 0;
    for(int i = 1; i <= N; i++)if(in[i])ans++;
    printf("%d\n",ans);
    return 0;
}
