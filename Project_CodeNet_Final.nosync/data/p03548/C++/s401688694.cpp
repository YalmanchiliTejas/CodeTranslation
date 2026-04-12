#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef  pair<int,int> P;
typedef long long LL;
typedef vector<LL> VEC;
typedef vector<VEC> VVEC;

const LL INF=1<<30;
const LL MOD=1000000007;






int main(){
    LL x,y,z;
    cin>>x>>y>>z;
    x-=z;
    y+=z;
    LL ans=x/y;
    cout<<ans<<endl;

}

