#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int r,g,b;
    cin >>r>>g>>b;
    cout<<((g*10+b)%4==0? "YES":"NO") << endl;
}