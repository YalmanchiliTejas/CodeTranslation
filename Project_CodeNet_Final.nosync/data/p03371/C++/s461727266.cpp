#include <bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;


int main(void){
    int a,b,c,x,y;
    cin >> a >> b>>c>>x>>y;
    int init=a*x+b*y;
    int s=0;
    while(true){
        s=0;
        if (x>0){
            s += a;
            x--;
        }
        if (y>0){
            s += b;
            y--;
        }
        int dif = s-2*c;
        // cout << init-dif << endl;
        if (dif>0)init-=dif;
        else break;
    }
    cout << init << endl;
    return 0;
}
