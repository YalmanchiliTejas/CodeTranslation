#pragma GCC optimize "-O3"
#include <bits/stdc++.h>
using namespace std;
#define lo long
const long long lmax=1000000000;
const long long lmx=1999999999999999999;
long long N,X,sz[52],p[52];
string s;
long long go(long long n,long long x)
{
//	cout<<n<<" "<<x<<endl;
	if(x<=0)return 0;
	if(n<0)return 0;
	if(x>=sz[n])return p[n];
	if(x>=(sz[n]+1)/2)return p[n-1]+1+go(n-1,x-sz[n]/2-1);
    return go(n-1,x-1);
}
int main(){std::ios::sync_with_stdio(false);
cin>>N>>X;
sz[0]=p[0]=1LL;
for(long long i=1;i<=N;i++)
{
	sz[i]=sz[i-1]*2LL+3LL;
	p[i]=p[i-1]*2LL+1LL;
}
cout<<go(N,X)<<endl;
}
/*

                   *         *
                  * *       * *
                 *   *     *   *
                *     *   *     *
               *       * *       *
               *        *        *
                *               *
                 *             *
                  *           *
                   *         *
                    *       *
                     *     *
                      *   *
                       * *
                        *



*/



