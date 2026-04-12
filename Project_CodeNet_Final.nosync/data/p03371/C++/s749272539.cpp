#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
using namespace std;

/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long  ll;


int main() {
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=a*x+b*y;
    ll z=0;
    while(x>0 or y>0){
        x--; y--;
        if(x<0)x=0;
        if(y<0)y=0;
        z+=2;
        ans=min(ans,a*x+b*y+c*z);
    }
    cout<<ans<<endl;





    return 0;
}
