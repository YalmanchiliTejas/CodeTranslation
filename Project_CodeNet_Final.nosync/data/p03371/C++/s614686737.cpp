#include <bits/stdc++.h>
using ll = long long;
using itn = int;
using namespace std;
int GCD(int a, int b){
    return b ? GCD(b, a%b) : a;
}
int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll res=0;
    //x,yの大小比較 yを大きくする
    if(x>y){
        swap(x,y);
        swap(a,b);
    }
    if(a+b > 2*c){
        res = x*2*c;
    }else{
        res = x*a+x*b;
    }
    y-=x;
    if(b>2*c){
        res += y*2*c;
    }else{
        res += y*b;
    }
    cout << res << endl;

}
