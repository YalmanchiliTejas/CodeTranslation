#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL N = 1234567;

inline LL read()
{
  LL p=0; LL f=1; char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
  while(ch>='0' && ch<='9'){p=p*10+(ch-'0'); ch=getchar();}
  return p*f;
}

int main()
{

  LL n=read(); LL k=read();
  
  LL ans = 0;
  for(LL b=k+1;b<=n;b++)
  {
    LL tim = n/b; LL s = 0;
    s += tim * (b-k);

    LL bb = n - tim * b;
    if(k) s += max( bb - k + 1, 0LL); 
    else if(bb) s+=bb;

    // prLLf("%d : %d\n",b,s);
    ans+=s;
  }
  return printf("%lld\n",ans),0;
}