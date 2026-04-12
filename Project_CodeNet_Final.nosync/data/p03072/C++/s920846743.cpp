#include <iostream>
using namespace std;

int main(){
    int N;
    int max = -1;
    int now = 0;
    int ans = 0;
    cin >> N;

    for (int i=0; i<N;i++){
        cin >> now;
        if(max <= now){
            ans++;
            max = now;
        }else{
            continue;
        }
    }
    cout << ans << endl;
    return 0;
}