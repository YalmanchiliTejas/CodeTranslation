// Created by ...
#include<bits/stdc++.h>
using namespace std;


#define mx 100005
#define ll long long 

void IO()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
}


int ar[mx];
char ch[mx];
int m,n,k,ii;
vector<int>mp;
vector<ll>v;
ll csum[mx];
void solve()
{
   ll a,b,c;
   scanf("%lld%lld%lld",&a,&b,&c);
   mp.push_back(b);
   ar[b]++;
   ll ace=0;
   ll st=0;
   for(ll i=2;i<=a;i++)
   {
      b*=b;
      b%=c;

      if(ar[b]>0)
        {

           ace=a-i+1;
           st=b;
           break;
       }
       mp.push_back(b);
       ar[b]++;
   }
   int idx=-1;
   int cnt=1;
   for(auto it:mp)
   {
   
      v.push_back(it);
      csum[cnt]=csum[cnt-1]+it;
      if(ace>0 && st==it)
      {
        idx=cnt;
      }
      cnt++;
   }
  // cout<<idx<<" "<<st<<endl;
   ll re=csum[cnt-1];
   if(ace>0)
   {
       ll barti=cnt-idx;
       ll ex=csum[cnt-1]-csum[idx-1];
       ll koto=ace/barti;
       int nibo=ace%barti;
       re+=ex*koto;
       for(int i=1;i<=nibo;i++)
       {
         re+=v[idx+i-2];
       }


   }
   printf("%lld\n",re );

}

int main()
{
   IO();
  int t=1;
  //scanf("%d",&t);
  while(t--)
  {
    solve();
  }
  return 0;
}