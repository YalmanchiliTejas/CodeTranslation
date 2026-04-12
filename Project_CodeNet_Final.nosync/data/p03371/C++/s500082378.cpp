#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int a,b,c,x,y,s,t,r;
    cin >> a >> b >> c >> x >> y;
   	if(x >= y){
    	s = (2*c*y + (x-y)*a);
    } 
    else{
     	s = (2*c*x + (y-x)*b);
    }
    t = (a*x + b*y);
    r = c*max(x,y)*2;
    cout << min({s,t,r}) << endl;
}