#include <bits/stdc++.h>
using namespace std;

//?#define FILE_AS_IO
#define SYNC_IO ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

int main() {
#ifdef FILE_AS_IO
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    SYNC_IO;
    
    int n;
    cin>>n;
    if (n >= 30) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}