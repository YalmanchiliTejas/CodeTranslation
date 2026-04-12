#include <iostream>
using namespace std;
typedef long long int lli;
int main(){
    lli k,a,b;
    cin >> k >> a >> b;
    if(a >= k){
        cout << 1 << endl;
    }else if(a-b <= 0){
        cout << -1 << endl;
    }else{
        cout << (k-b-1)/(a-b)*2 +1 << endl;
    }
    return 0;
}
