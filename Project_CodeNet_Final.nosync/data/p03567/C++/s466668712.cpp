    #include<iostream>
    #include<algorithm>
    #include<cstdio>
    #include<cstdlib>
    #include<string>
    #include<cstring>
    #include<cmath>
    #include<vector>
    #include<set>
    #include<map>
    #include<stack>
    #include<queue>
    #include<time.h>
    #define ll long long
    #define mp make_pair
    #define pb push_back
    #define lson l,mid,pos<<1
    #define rson mid+1,r,pos<<1|1
    using namespace std;

    const int maxn=200000+3;
    //const int maxm=2000+5;
    //const ll mod=1e9 + 7;
    //const int inf=0x3f3f3f3f;
    //const double PI=acos(-1);
    //const double eps=1e-8;
    //int dir[4][2]={0,1,1,0,0,-1,-1,0};
    //const ll INF = 0x3f3f3f3f3f3f3f3fLL;
    //ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
    //ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
    //ll inv(ll b){if(b==1) return 1; return (mod-mod/b)*inv(mod%b)%mod;}
    //ll fpow(ll n,ll k){ll r=1;for(;k;k>>=1){if(k&1)r=r*n%mod;n=n*n%mod;}return r;}

      char s[10];
    int main()
    {
      scanf("%s", s);
      if(strstr(s, "AC")!=NULL)
      {
          cout<<"Yes"<<endl;
      }
      else
        cout<<"No"<<endl;
      return 0;
    }
