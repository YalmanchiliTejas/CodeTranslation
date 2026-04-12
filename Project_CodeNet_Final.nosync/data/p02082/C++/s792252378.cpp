#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
    int s,t;
    cin >> s >> t;
    int p,q,m,y;
    cin >> p >> q >> m >> y;
    int aa = s^t;
    cout << (y^aa) << endl;
    return 0;
}
