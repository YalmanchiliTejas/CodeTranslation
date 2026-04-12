#include <iostream>
#include <algorithm>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int n,m;
    cin >> n >> m;
    string ans;
    if(n == m)ans = "Yes";
    else ans="No";
    cout << ans << endl;
}
