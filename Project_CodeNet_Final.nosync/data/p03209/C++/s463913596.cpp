#include <iostream>
#include <vector>
using namespace std ;
using LL = long long int;


LL paty(int n,LL x,vector<LL> l,vector<LL> p)
{
    if(n==0) return 1;
    if(x == 1)
    {
        return 0;
    }
    if(x == l[n-1]+2)
    {
        return p[n-1]+1;
    }
    if(x == 2*l[n-1]+3)
    {
        return p[n];
    }
    if(x < l[n-1]+2)
    {
        return paty(n-1,x-1,l,p);
    }
    if(x > l[n-1]+2)
    {
        return  p[n-1]+paty(n-1,x-l[n-1]-2,l,p)+1;
    }
}

int main(){
    LL x;
    int n;
    cin >> n >> x;
    vector<LL> l(n+1);
    vector<LL> p(n+1);
    l[0] = 1;
    p[0] = 1;
    for(int i = 1; i< n+1;i++ )
    {
        l[i] = l[i-1]*2+3;
        p[i] = p[i-1]*2+1;
    }
    LL ans = paty(n,x,l,p);
    cout << ans << endl;
}