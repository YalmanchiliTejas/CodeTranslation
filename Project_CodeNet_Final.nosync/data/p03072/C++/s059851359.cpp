#include<iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int h[n];
    for(int i=0; i<n; i++) cin >> h[i];

    int sum = 1,high = h[0];
    for(int i=1; i<n; i++){
        if(high <= h[i]){
            high = h[i];
            sum++;
        }
    }

    cout << sum << endl;
    
    return 0;
}