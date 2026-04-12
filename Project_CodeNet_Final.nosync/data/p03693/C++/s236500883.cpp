#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

signed main()
{
    int r,g,b; cin>>r>>g>>b;
    int a=100*r+10*g+b;
    if(a%4==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}
