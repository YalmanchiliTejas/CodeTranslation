#include <bits/stdc++.h>
using namespace std;
 
int main(void){
    int n;
    cin >> n;
    int height = 0;
    int count = 0;
    for(int i = 0;i < n;i++){
        int h;
        cin >> h;
        if(height <= h){
            height = h;
            count++;
        }
    }

    cout << count;
}