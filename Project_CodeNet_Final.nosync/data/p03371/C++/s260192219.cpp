#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int long long total=0;
    if(a+b>2*c){
        total = min(x,y)*c*2;
        if(x>y){
            if(2*c<a){
                total = max(x,y)*c*2;
            }
            else{
                total += (x-y)*a;
            }
        }
        else{
            if(2*c<b){
                total = max(x,y)*c*2;
            }
            else{
                total += (y-x)*b;
            }
        }
    }
    else{
        total = a*x + b*y;
    }
    cout << total << endl;
    return 0;
}