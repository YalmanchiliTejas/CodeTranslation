#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int H[n];
    for(int i = 0; i < n ;i++){
        cin >> H[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        bool counter = true;
        for(int j = 0; j < i; j++){
            if(H[j] > H[i]){
                counter = false;
                break;
            }
        }
        if(counter == true){
            count += 1;
        }
    }

    cout << count << endl;
    return 0;
}
 