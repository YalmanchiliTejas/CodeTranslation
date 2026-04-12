#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mk make_pair
#define MAX (lld)1e18+7
#define lim (lld)1e9+7
#define MAX2 (int)2e5+9
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


int extend_gcd(int a, int b, int& x, int& y) {
    if (b == 0) { x = 1;y = 0;return a;}
    int x1, y1;
    int d = extend_gcd(b, a % b, x1, y1);
    x = y1; y = x1 - y1 * (a / b);return d;	}

int rowNum[]={-1,0,0,1};
int colNum[]={0,-1,1,0};

int main()
{
	fastio
	int x;
	cin>>x;

	if(x>=30)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}