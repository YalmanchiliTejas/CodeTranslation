#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,x,y;
    int piza = 0,pizb = 0,pizc =0;
    cin >> a >> b >> c >> x >> y;
    int ans = a*x + b*y;
    if(a + b <= 2*c){
        piza = x;
        pizb = y;
        ans = a*piza + b*pizb;
    }else{
        for(int i = 0;i <= max(x,y);i++){
            pizc = 2*i;
            piza = max(0,x - pizc/2);
            pizb = max(0,y - pizc/2);
            ans = min(ans,a*piza + b*pizb + c*pizc);
        }
    }
    
    cout << ans << endl;
    return 0;
}
