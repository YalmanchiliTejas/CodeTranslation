#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    cout<<((g*10+b)%4==0?"YES":"NO")<<endl;
    return 0;
}