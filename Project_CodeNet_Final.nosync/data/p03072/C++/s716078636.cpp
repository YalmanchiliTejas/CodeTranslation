#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,ans=0;
    cin >> N;
    vector<int> H(N);
    for(int i=0; i<N; i++){
        cin >> H[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            if(j==i){
                ans++;
                break;
            }
            if(H[i]<H[j]){
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}