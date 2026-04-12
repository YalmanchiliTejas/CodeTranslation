#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int ans;
    ans = 1;
    int h1;
    cin >> h1;
    int max;
    max = h1;
    int h;
    for(int i=1; i < N; i++){
        cin >> h;
        if(max <= h){
            max = h;
            ans++;
        }
    }
    cout << ans << endl;
}
