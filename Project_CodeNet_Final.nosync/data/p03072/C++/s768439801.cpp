#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int n,mx,cnt;
    cin >> n;
    cnt =0,mx = -1;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        if(mx <= temp){
            cnt++;
            mx = temp;
        }
    }
    cout << cnt;
    return 0;
}
