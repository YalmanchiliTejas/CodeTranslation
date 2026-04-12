#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = 10*b+c;
    if(ans % 4==0)cout << "YES" <<endl;
    else cout << "NO"<<endl;
}
