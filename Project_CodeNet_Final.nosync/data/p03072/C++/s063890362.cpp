#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin >> n;
    int ans=0,max=0;
    for(int i=0;i<n;i++){
        int h;
        cin >>h;
        if(max <= h){
            ans++;
            max = h;
        }
    }
    cout << ans << endl;
}
