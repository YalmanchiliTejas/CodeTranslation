#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include<algorithm> 
#include <iomanip>
#include <math.h>
#include <cctype>
//小文字を大文字 c-0x20;


#define db double
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define maxn 5005
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vv(z,a,b) vector<vector<int>>z(a,vector<int>(b))
#define vvll(z,a,b) vector<vector<ll>>z(a,vector<ll>(b))
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) c.begin(),c.end()
#define fix(k) fixed<<setprecision(k)
#define PI 3.141592653589793
#define sizestr(i,x)  size_t i=x.length();
using namespace std;



int main(){
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    ll h;
    if(x>y)h=2*x;
    else h=2*y;
    ll flag;
    ll ju=10000000000000000;
    for(int i=0;i<=h;i+=2){
        int g,k;
        if((x-i/2)<0)g=0;
        else g=x-i/2;
        if((y-i/2)<0)k=0;
        else k=y-i/2;

        flag=a*g+b*k+c*i;
        if(ju>flag)ju=flag;
    }

    cout<<ju<<endl;
}
