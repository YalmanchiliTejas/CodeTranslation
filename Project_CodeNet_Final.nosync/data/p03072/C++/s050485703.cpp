#include <iostream>
using namespace std;

int N,H[21] = {};
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> H[i];
    }
    int ans = 1;
    for(int i=2;i<=N;i++){
        bool judge =true;
        for(int j=1;j<i;j++) if(H[j]>H[i]) judge = false;
        ans += judge;
    }
    cout << ans << endl;
}