#include<iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int h[n];
    for(int i=0;i<n;i++)cin >> h[i];

    int ans = 0, highest = 0;
    for(int i=0;i<n;i++){
        if(h[i]>=highest){
            ans++;
            highest = h[i];
        }
    }
    cout << ans << endl;
}
