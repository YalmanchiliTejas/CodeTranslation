#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<int> h(n, 0);
    for(int i=0;i<n;++i) cin >> h[i];
    int c = 1; n = h[0];
    for(auto v = h.begin()+1;v!=h.end();++v) {
        if(*v>=n) ++c;
        n = max(*v,n);
    }
    cout << c << endl;
    return 0;
}
