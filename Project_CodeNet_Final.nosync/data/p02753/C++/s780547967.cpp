#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
//#define MOD 998244353
#define MOD 1000000007

int main(){
    char s[4];
    scanf("%s",s);
    if(s[0]!=s[1]||(s[1]!=s[2]||s[0]!=s[2]))printf("Yes");
    else printf("No");
}