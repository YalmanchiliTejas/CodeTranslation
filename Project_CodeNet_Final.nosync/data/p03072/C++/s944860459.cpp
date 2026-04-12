#include <bits/stdc++.h>
using namespace std;

int main() {
    //input
    int n,h;
    cin >> n;
    int m = 0;
    int count=0;
    for(int i=0;i<n;i++){
        cin >> h;
        if(m<=h){
            count++;
            m = h;
        }
    }
    cout << count;

    return 0;
}