#include<bits/stdc++.h>
using namespace std;
int main(){
    long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long ans = 1L << 50;
    for(long i=0;i<=200000;i+=2){
        long tmp = 0;
        tmp += c*i;
        if(x*2 > i)tmp += a * (x-i/2);
        if(y*2 > i)tmp += b * (y-i/2);
        ans = min(tmp,ans);
    }
    cout << ans << endl;
}