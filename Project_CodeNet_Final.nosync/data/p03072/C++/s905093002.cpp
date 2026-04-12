#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int h[110];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int count = 1;
    for(int i=1; i<n; i++){
        bool isOk = true;
        for(int j=0; j<i; j++){
            if(h[j]>h[i]){
                isOk = false;
            }
        }
        if(isOk){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}