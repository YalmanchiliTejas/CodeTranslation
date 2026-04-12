#include <iostream>

using namespace std;

int main(){
    string ans;
    int n,m;
    cin >> n >> m;
    if(n==m){
        ans="Yes";
    }
    else{
        ans="No";
    }
    
    cout << ans << endl;
    return 0;
}