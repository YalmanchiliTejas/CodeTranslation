#include<iostream>
using namespace std;

int main(void){
    int i, N;
    cin >> N;
    int H[N];
    for(i=0; i<N; i++){cin >> H[i];}
    int max, ans;
    ans = 1;
    max = H[0];
    for(i=1; i<N; i++){
        if(max<=H[i]){
            ans++;
            max = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}