#include <bits/stdc++.h>
using namespace std;

int64_t zyo = 1000000007;

int main(){
    int64_t N;
    cin >> N;
    vector<int64_t> A(N,0);
    for (int64_t i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int64_t sum = 0,sum_2 = 0,ans;
    for (int64_t i = 0; i < N; i++){
        sum += A.at(i);
        sum = sum % zyo;
        sum_2 += A.at(i) * A.at(i) % zyo;
        sum_2 = sum_2 % zyo;
    }
    ans = sum*sum%zyo;
    ans -= sum_2;
    if(ans < 0){
        ans += zyo;
    }
    if(ans % 2 == 0){
        ans = ans/2;
    }else{
        ans += zyo;
        ans = ans/2;
    }
    cout << ans << endl;
}