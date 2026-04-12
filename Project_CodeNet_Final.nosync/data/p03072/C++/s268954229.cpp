#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans=1;
    int h[N];
    for(int i=0;i<N;i++)cin >> h[i];
    int MAX=h[0];
    for(int i=1;i<N;i++){
        if(h[i]>=MAX){
            ans++;
            MAX=h[i];
        }
    }
    cout << ans << endl;
}