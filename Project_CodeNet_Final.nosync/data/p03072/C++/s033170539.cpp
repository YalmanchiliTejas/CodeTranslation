#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int h[30];
    for(int i = 0;i < n;i++)cin >> h[i];
    int cnt = 0;
    int ma = 0;
    for(int i = 0;i < n;i++){
        if(ma <= h[i])cnt++,ma = h[i];
    }
    cout << cnt << endl;
}