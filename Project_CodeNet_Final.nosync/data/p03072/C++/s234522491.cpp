
#include <iostream>
#include <vector>
using namespace std;
void a(){
    int A,B; cin >> A >> B;

    int ans = 0;
    if (A > B){
        ans +=A;A--;
    } else {
        ans += B;
        B--;
    }

    if (A > B){
        ans +=A;A--;
    } else {
        ans += B;B--;
    }

 cout << ans;

}

void b(){

    int N; cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }

    int c = 0;
    int max_h = 0;
    for(int i = 0; i < N ;i++){

        if(max_h <= H[i]){
            c++;
            max_h = H[i];
        }
    }

    cout << c;

}

int main(){
    b();
    return 0;
}
