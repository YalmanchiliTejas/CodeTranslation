#include<bits/stdc++.h>
#define ll long long

int take()
{
    int n;
    scanf("%d",&n);
    return n;

}

ll takes()
{
    ll n;
    scanf("%lld",&n);
    return n;

}
#define M 5005
#define Int take()
#define LL takes()
#define end return 0
#define fo(n) for(int i=1;i<=n;i++)
#define rfo(n) for(int i=n;i>=1;i--)
int cas;
#define print printf("Case %d:",++cas)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define mk  make_pair
#define fill(x,v) memset(x,v,sizeof x)
using namespace std;

int main(){
    string s;
    cin>>s;
    bool ans=0;

    for(int i=1;i<(s.size());i++){
        string p="";
        p+=s[i-1];p+=s[i];
        if(p=="AC") ans=1;
    }

    if(ans) printf("Yes\n");
    else printf("No\n");
end;
}
