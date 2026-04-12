#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main(){
    int r,g,b;
    cin>>r>>g>>b;
    int p=100*r+10*g+b;
    if(p%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}