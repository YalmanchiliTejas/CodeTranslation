#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin>>n;
    int res=0, maxh=-1;
    for(int i=0; i<n; ++i) {
        int h; cin>>h;
        maxh=max(h, maxh);
        if (h==maxh) ++res;
    }
    cout<<res<<endl;
}
