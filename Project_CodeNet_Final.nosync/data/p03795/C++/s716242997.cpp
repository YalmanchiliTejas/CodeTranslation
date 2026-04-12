/*     Abhinav Vaishya (abhinav_2812)          */
/*     DA-IICT                    */


#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> vi;
typedef vector<long long> vl;


#define MOD 1000000007
#define si(n) scanf("%d",&n)
#define sd(n) scanf("%lf",&n)
#define sl(n) scanf("%lld",&n)
#define sld(n) scanf("%Lf",&n)
#define ss(s) scanf("%s",s)
#define pi(n) printf("%d",n)
#define pd(n) printf("%lf",n)
#define pl(n) printf("%lld",n)
#define pld(n) printf("%Lf",n)
#define ps(s) printf("%s",s)
#define pline printf("\n")
#define _for(i,a,n) for(int i=a; i<n; i++)
#define __for(i,a,n) for(int i=a; i<=n; i++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(x) x.begin(),x.end()

int max_ar(vi &a);
int min_ar(vi &a);
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b);

//----Code starts here----//
int main() {
        int n;
        si(n);
        pi(n*800 - (n/15)*200); pline;
        return 0;
}
//----Code ends here----//



//maximum element in a vector
int max_ar(vi &a) {
        int mx=-1;
        _for(i,0,a.size()) mx=max(mx,a[i]);
        return mx;
}

//minimum element in a vector
int min_ar(vi &a) {
        int mn=1000000000;
        _for(i,0,a.size()) mn=min(mn,a[i]);
        return mn;
}

//sort a pair vector by second element
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) {
        return (a.second < b.second);
}
