#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
const int maxn=1e5+5;
int main()
{
    int n,k;
    string s;
    scanf("%d",&n);
    cin>>s;
    scanf("%d",&k);
    rep(i,n)
    {
        if(s[i]!=s[k-1]) printf("*");
        else printf("%c",s[i]);
    }
    printf("\n");
}
