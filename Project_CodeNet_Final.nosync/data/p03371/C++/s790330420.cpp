#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,d,e;
    long long ans=0;
    cin >> a >> b >> c >> d >> e;
    if(a+b<=c*2){
        ans = a*d + b*e;
    }else{
        if(d==e){
            ans = c*d*2;  
        }else if(d<e){
            ans = c*min(d,e)*2;
            if(b>c*2){
                ans += c*abs(d-e)*2;
            }else{
                ans += b*abs(d-e);
            }
        }else{
            ans = c*min(d,e)*2;
            if(a>c*2){
                ans += c*abs(d-e)*2;
            }else{
                ans += a*abs(d-e);
            }
        }
        
    }
    cout << ans << endl;
}