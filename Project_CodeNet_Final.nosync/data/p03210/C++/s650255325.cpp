#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
typedef long long ll;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

int main(){
    int x;
    cin >> x;
    if(x==3||x==5||x==7){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}