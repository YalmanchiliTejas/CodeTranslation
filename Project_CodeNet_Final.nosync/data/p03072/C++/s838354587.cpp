#include<iostream>
using namespace std;

int main(void){
    int n, h[20], result = 1;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 1; i < n; i++){
        bool can = true;
        for(int j = 0; j < i; j++){
            if(h[j] > h[i]) can = false;
        }
        if(can) result++;
    }
    cout << result << endl;
    return 0;
}