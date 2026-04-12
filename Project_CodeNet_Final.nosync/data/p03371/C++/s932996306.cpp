#include <bits/stdc++.h>
using namespace std;

int main() {

    int a,b,c,x,y;

    cin >> a >> b >> c >> x >> y;

    int ans = 0;
/*
    if(a < c && b < c){
        ans =  a*x + b*y;
    }
    else if(a>c && b>c){
        for(int i=0; i<max(x,y); i++){
            ans += c*2;
        }
    }
    else{*/
        int p=0;
        int tx = x , ty = y;
        for(int i=0; i<min(x,y); i++){
            p += c*2;
            tx--;
            ty--;
        }
        if(tx > 0){
            p += a*tx;
        }
        else if(ty > 0){
            p += b*ty;
        }
        int o = 0;
        for(int i=0; i<max(x,y); i++){
            o += c*2;
        }
        int cy = a*x + b*y;
        ans = min(min(p,o),cy);
    //}

    cout << ans << endl;

    return 0;
}