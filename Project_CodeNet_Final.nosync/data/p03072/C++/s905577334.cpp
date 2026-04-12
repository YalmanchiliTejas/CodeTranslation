#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int ans = 1;

    for(int i=1; i<n; i++){
        int judge = 0;
        for(int j=0; j<i; j++){
            if(h[j]<=h[i]){
                judge += 1;
            }if(judge == i){
                ans += 1;
            }
        }
    }

    cout << ans;
    
    return 0;
}