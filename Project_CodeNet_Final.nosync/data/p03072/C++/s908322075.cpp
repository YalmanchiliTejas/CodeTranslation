#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, i = 0, j = 0, count = 0, flag = 0;
    cin >> n;
    int h[n];
    for(i = 0; i < n; i++){
        cin >> h[i];
    }
    count = 1;
    for(i = 1; i < n; i++){
        flag = 0;
        for(j = 0; j < i; j++){
            
            if(h[i] >= h[j]){
                flag = 1;
            }
            else{
                flag = 0;
                break;
            }
            
        }
        if(flag == 1){
            count++;
        }
    }
    cout << count << endl;
}