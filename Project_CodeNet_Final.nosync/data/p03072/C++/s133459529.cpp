#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int tmp;
    int flag = 0;
    int max = 0;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp >= max) {
            max = tmp;
            flag++;
        }
    }
    cout << flag << endl;
    return 0;
}