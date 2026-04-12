#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, mx = 0, res = 0;
    cin >> a;
    while(cin >> a){
        if(a == (mx = max(mx, a))) res++;
    }
    cout << res;
}