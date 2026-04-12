#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans=0;
    if(c*2<=a+b){
        int c_num=min(x,y)*2;
        ans+=c*c_num;
        int x_num=x-min(x,y);
        int y_num=y-min(x,y);
        ans+=a*x_num+b*y_num;
        ans=min(ans,c*max(x,y)*2);
    }else{
        ans+=x*a+y*b;
    }
    cout << ans << endl;
}
