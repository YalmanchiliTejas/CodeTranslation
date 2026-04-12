#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int r,g,b; cin >> r >> g >> b;
    puts((r*100+g*10+b)%4==0?"YES":"NO");
}