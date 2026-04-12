#include<bits/stdc++.h>
using namespace std;
const int maxN = 3010;
const long long P = 998244353;
long long a[maxN],sumL[maxN][maxN];
int main()
{
    int N,S;
    scanf("%d%d",&N,&S);
    for(int i=1;i<=N;i++)scanf("%lld",&a[i]);
    long long ans=0;
    for(int i=1;i<=N;i++)
    {
        if(a[i]==S)ans=(ans+i*(N-i+1))%P;
        else if(i-1>0&&S-a[i]>0)ans=(ans+((sumL[i-1][S-a[i]]*(N-i+1))%P))%P;
        sumL[i][a[i]]=i%P;
        for(int k=1;k<=S;k++)
        {
            sumL[i][k]=(sumL[i][k]+sumL[i-1][k])%P;
            if(k-a[i]>0)sumL[i][k]=(sumL[i][k]+sumL[i-1][k-a[i]])%P;
        }
    }
    printf("%lld",ans%P);
}
