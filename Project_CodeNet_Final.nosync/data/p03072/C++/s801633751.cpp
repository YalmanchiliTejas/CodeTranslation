#include <iostream>
using namespace std;

int main(){
    int N;
    int i,j;
    i=0;
    j=1;
    int ans; //海を眺められる旅館の数
    ans=1;

    int H[20];
    cin >> N;
    for(i=0; i < N; i++){
        cin >> H[i];
    }
    for (i=1; i<N; i++){
        for(j=0; j<=i; j++){
            if (j==i){
                ans =ans +1;
            }
            else if (H[i]<H[j]){
                break;
            }
        }
    }
    cout << ans << endl;
}