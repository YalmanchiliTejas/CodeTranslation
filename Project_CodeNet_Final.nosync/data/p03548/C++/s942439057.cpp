#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,_4,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n,s) for (int i=n-1;i>=a;i--)
#define range(...) _overload3(__VA_ARGS__,per,repi,_rep,)(__VA_ARGS__)
#define _GLIBCXX_DEBUG
// head

int main(){
    int x,y,z;
    cin >>x>>y>>z;
    cout << (x-z)/(y+z)<<endl;
}