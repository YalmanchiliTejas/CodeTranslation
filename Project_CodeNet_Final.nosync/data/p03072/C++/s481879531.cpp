#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 1; //1番目の旅館は必ず海が見える
    int h[n];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    bool flag = false;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(h[j] <= h[i]){
                flag = true;
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag){
            count++;
        }
    }
    cout << count << endl;
}