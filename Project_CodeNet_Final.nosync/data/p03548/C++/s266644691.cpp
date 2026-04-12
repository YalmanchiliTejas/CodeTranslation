#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>
#include<array>
#include<numeric>
#include<iomanip>
#include<functional>

using namespace std;
typedef long long int ll;

#define C(I) cout<<(I)<<endl

ll n,m,a,b,c,x,y,z,aa[100010],ba[100010];
bool r,ra,rb,rc;
string s,sa,sb,sc;
char ca,cb,cc;
vector<ll> va,vb,vc;


int main(){
    cin>>x>>y>>z;
    a=0;
    while(y*a+a*z+z<=x){
        a++;
    }
    C(a-1);
}