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

ll n,m,a,b,c,x,y,aa[100010],ba[100010];
bool r,br,ar;
string s;
char ca,cb;


int main(){
    cin>>a>>b>>c;
    r=(a*100+b*10+c)%4==0;
    cout<<(r ? "YES":"NO")<<endl;
    
}
