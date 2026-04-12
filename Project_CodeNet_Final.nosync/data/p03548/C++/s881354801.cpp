#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

signed main()
{
    int x,y,z; 
    cin>>x>>y>>z;
    x-=y+2*z;
    cout<<1+x/(y+z)<<endl;
}
