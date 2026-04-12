#include <iostream>

using namespace std;

int main(){
    int N;
    long a[50];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    long ans = 0;
    long cnt = 0;
    while(true){
        cnt = 0;
        for(int i = 0; i < N; i++){
            cnt += a[i]/N;
            a[i] = a[i] - (N+1)*(a[i]/N);
        }
        for(int i = 0; i < N; i++){
            a[i] += cnt;
            //cout << a[i] << ' ';
        }
        //cout << endl;
        if(cnt == 0) break;
        ans += cnt;
    }
    cout << ans << endl;
}