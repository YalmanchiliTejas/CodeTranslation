#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int h[N];
    int nowh = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }

    for(int i = 0; i < N; i++){
        if(nowh <= h[i]){
            ans++;
            nowh = h[i];
        }
    }
    cout << ans << endl;
}