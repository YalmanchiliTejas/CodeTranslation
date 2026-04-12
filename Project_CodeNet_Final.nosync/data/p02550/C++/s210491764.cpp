#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mk make_pair
#define MAX (lld)1e18+7
#define lim (lld)1e9+7
#define MAX2 (lld)2e5+9
#define ff first
#define ss second
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const lld mod=lim;

lld power(lld x, lld y, lld p)  
{   lld res = 1;     x = x % p; if (x == 0) return 0;  
  
    while (y > 0)  
    { if (y & 1) res = (res*x) % p;  y = y>>1; x = (x*x) % p;   }  
    return res;  } 


lld extend_gcd(lld a, lld b, lld& x, lld& y) {
    if (b == 0) { x = 1;y = 0;return a;}
    lld x1, y1;
    lld d = extend_gcd(b, a % b, x1, y1);
    x = y1; y = x1 - y1 * (a / b);return d;	}

lld rowNum[]={-1,0,0,1};
lld colNum[]={0,-1,1,0};

int main()
{
	fastio
	lld n,x,m;
	cin>>n>>x>>m;
	map<lld,lld> cnt;
	lld nxt = x;
	lld sum=0;
	cnt[x]++;
	sum+=x;
	lld idx=n;
	for(lld i=1;i<min(n,m);i++)
	{
		nxt = (nxt*nxt)%m;

		if(cnt.find(nxt)!=cnt.end())
		{	
			idx=i;
			break;
		}
		else
		{	
			sum+=nxt;
			cnt[nxt]++;
		}
	}

	cnt.clear();
	cnt[nxt]++;
	lld len=1;
	std::vector<lld> cycsum;
	cycsum.pb(nxt);
	lld lensum=nxt;
	for(lld i=idx;i<min(n,m+idx);i++)
	{
		nxt = (nxt*nxt)%m;

		if(cnt.find(nxt)!=cnt.end())
		{
			break;
		}

		else
		{
			len++;
			cycsum.pb(nxt);
			lensum+=nxt;
			cnt[nxt]++;
		}
	}
	lld cycles = (n-(idx))/len;
	sum = sum + ((cycles)*(lensum));

	for(lld i=0;i<(n-idx)-cycles*len;i++)
	{
		sum+=cycsum[i];
	}

	cout<<sum<<endl;
}