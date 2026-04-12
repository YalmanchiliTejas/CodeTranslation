#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,l,n) for(int i=(l);i<(n);i++)

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >>y;
    if(a+b < 2*c){
        cout << a*x+b*y << endl;
    }
    else{
        int i = min(x,y);
        int j = max(x,y);
        if(x > y){
            cout << min(j*2*c,i*2*c+(j-i)*a) << endl;
        }
        else {
            cout << min(j*2*c,i*2*c+(j-i)*b) << endl;
        }

    }
    return 0;
}
