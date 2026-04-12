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

const LL INF=1<<30;
const LL MOD=1000000007;

LL gcd(LL a,LL b){
    if(b==0)return a;

    return gcd(b,a%b);
}


int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if((2*b+c)%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}