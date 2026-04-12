#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int h, w; cin>>h>>w;
    vector<string> s(h); for(e: s) cin>>e;
    bool ok=true;
    for(int i=0; i+1<h; ++i)
        for(int j=0; j+1<w; ++j) {
            if (s[i][j]=='#' and s[i][j+1]=='#' and s[i+1][j]=='#') ok=false;
            if (s[i+1][j]=='#' and s[i][j+1]=='#' and s[i+1][j+1]=='#') ok=false;
        }
    cout<<(ok ? "Possible" : "Impossible")<<endl;
}
