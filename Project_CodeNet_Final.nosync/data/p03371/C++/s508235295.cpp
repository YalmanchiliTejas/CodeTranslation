#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

#define REP(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))

int a,b,c,x,y;


int main()
{
    cin >> a >> b >> c >> x >>y;
    int p[2] = {a,b};
    bool i = x<y;
    int ans = 0;
    if(a+b < 2*c){
        cout << a*x+b*y << endl;
        return 0;
    }else{
        ans = min(x,y)*2*c;
        int k = abs(x-y);
        ans += min(p[i]*k,2*c*k);
        cout << ans << endl;
        return 0 ;
    }
}