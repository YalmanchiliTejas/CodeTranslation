#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    int x;
    cin>>x;
    if(x!=3 && x!=5 && x!=7) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}