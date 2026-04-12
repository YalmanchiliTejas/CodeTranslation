#include <iostream>
using namespace std;

int main(){
    int n, cnt=0, max=0; cin >> n;
    for(int i = 0; i < n; i++){
        int h; cin >> h;
        if(h>=max){
            cnt++; max = h;
        }
    }
    cout << cnt << endl;
    return 0;
}
