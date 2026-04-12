#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <assert.h>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long int
#define db double
#define ldb long double
#define MOD 1000000007
#define Fi first
#define Se second
#define INF INT_MAX
#define NINF INT_MIN
#define L_INF LLONG_MAX
#define L_NINF LLONG_MIN
#define gc getchar
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define pll pair<ll,ll>

void fsscan(){ios_base::sync_with_stdio(false);cin.tie(NULL);}

void scani(int &x)
{
    register int c = gc();x = 0;int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main()
{
    fsscan();
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int v1,v2,v3,v4,v5;
    v1=a*x+b*y;
    if(x>y)
    {
        v2=(x-y)*a+2*c*(y);
    }
    else
    {
        v2=2*c*(y);
    }
    if(y>x)
    {
        v3=(y-x)*b+2*c*(x);
    }
    else
    {
        v3=2*c*(x);
    }
    v4=(2*c*max(x,y));
    //cout<<v1<<" "<<v2<<" "<<v3<<" "<<v4<<endl;
    cout<<min(v1,min(v2,min(v3,v4)));
    return 0;
}
