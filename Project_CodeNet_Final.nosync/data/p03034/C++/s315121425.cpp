#include<iostream>
using namespace std;

int N;
long long s[100000];


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    long long ans = 0;
    for(int d = 1; d < N - 1; d++){ // d = A - B
        long long tmp_score = 0;
        for(int k = 1; N - 1 - k * d > d; k++){
            if((N - 1) % d == 0 && (N - 1 - k * d) <= k * d){
                continue;
            }
            tmp_score += s[k * d] + s[N - 1 - k * d];
            ans = max(ans, tmp_score);
        }
    }
    cout << ans << endl;
        

}
