#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int suma,sumb,sumc=1000000000,sumd=1000000000;
    suma = 2*c*max(x,y);
    sumb = a*x+b*y;
    if(x-y > 0) sumc = a*(x-y) + 2*c*y;
    if(y-x > 0) sumd = 2*c*x + b*(y-x);
    int minimum = min(sumd,min(sumc,min(suma,sumb)));
    cout << minimum << endl;
    return 0;
}