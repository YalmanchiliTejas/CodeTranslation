#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    int N; 
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll sum = 0;
    if(N % 2 != 0){
        ll temp = 0;
        int limit = N / 2;
        for(int i = 0; i < N; ++i){
            if(i < limit){
                temp -= 2 * A[i];
            }
            else{
                temp += 2 * A[i];
            }
        }
        temp -= A[limit] + A[limit + 1];
        sum = max(sum, temp);
        
        temp = 0;
        for(int i = 0; i < N; ++i){
            if(i <= limit){
                temp -= 2 * A[i];
            }
            else{
                temp += 2 * A[i];
            }
        }
        temp += A[limit - 1] + A[limit];
        sum = max(sum, temp);
    }
    else{
        int limit = N / 2;
        for(int i = 0; i < N; ++i){
            if(i < limit){
                sum -= 2 * A[i];
            }
            else{
                sum += 2 * A[i];
            }
        }
        sum += A[limit - 1];
        sum -= A[limit];
    }
    cout << sum << endl;
}