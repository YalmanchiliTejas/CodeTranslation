#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    if (x>y) {
        swap(x,y);
        swap(a,b);
    }
    c=min(c*2,a+b);
    b=min(c,b);
    cout<<c*x+b*(y-x)<<endl;
    return 0;
}