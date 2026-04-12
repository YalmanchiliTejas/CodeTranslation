#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){
    int n; cin>>n;

    int pay = 800*n;
    int pay_back = 200*(n/15);

    cout<<pay-pay_back<<endl;
}

int main(){
    solve();
    Bye;
}