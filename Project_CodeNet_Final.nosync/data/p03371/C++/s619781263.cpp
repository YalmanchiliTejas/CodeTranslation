#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long long int ans = a*x+b*y;
    
    for(int i = 0;i <= max(x,y);i++){
        long long int sum = (i*2)*c;
        if((x-i) > 0)sum += (x-i)*a;
        if((y-i) > 0)sum += (y-i)*b;
        ans = min(ans,sum);
    }
    
    cout << ans << endl;
}