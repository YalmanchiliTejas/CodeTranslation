#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) { //最小公倍数
  return a * b / gcd(a, b);
}

ll digit_sum(ll a){ //10進桁和
  ll ans=0;
  while(a>0){
    ans+=a%10;
    a/=10;
  }
  return ans;
}



int main()
{
  ll h,w;
  char a[110][110];
  bool flag[110][110]={false};
  bool flag2[110][110]={false};
  cin>>h>>w;
  rep(i,h){
    rep(j,w)cin>>a[i][j];
  }


  rep(i,h){
    ll tmp=0;
    rep(j,w){
      if(a[i][j]=='#')tmp++;
    }
    if(tmp!=0){
      rep(k,w){
        flag[i][k]=true;
      }
    }
  }


  rep(i,w){
    ll tmp=0;
    rep(j,h){
      if(a[j][i]=='#')tmp++;
    }
    if(tmp!=0){
      rep(k,h)flag2[k][i]=true;
    }
  }

  rep(i,h){
    ll tmp=0;
    rep(j,w){
      if(flag[i][j]&&flag2[i][j]){
        cout<<a[i][j];
        tmp++;
      }
    }
    if(tmp>0)cout<<endl;
  }
  return 0;
}
