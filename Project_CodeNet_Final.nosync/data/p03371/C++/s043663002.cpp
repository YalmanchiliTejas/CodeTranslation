#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int a,b,c,x,y;
int ans;

int main() {
    cin>>a>>b>>c>>x>>y;
    if (x<y) {swap(x,y);swap(a,b);}
    int delta=x-y;
    ans+=min(y*(a+b),y*c*2);
    ans+=min(delta*a,delta*c*2);
    cout << ans;
}