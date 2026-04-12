#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for ( int i = 0; i < N; ++i){
        cin >> A.at(i);
    }
    int64_t res = 0;
    if ( N % 2 == 0 ){
        int64_t ans[N][2];
        for ( int i = 0; i < N; ++i){
            if ( i >= 2 ){
                ans[i][0] = ans[i-2][0] + A.at(i);
            } else if ( i == 0 ) {
                ans[i][0] = A.at(i);
            } else {
                ans[i][0] = 0;
            }
        }
        for ( int i = 0; i < N; ++i){
            if ( i >= 3 ){
                 ans[i][1] = max(ans[i-3][0], ans[i-2][1]) + A.at(i);
            } else if ( i == 1 ) {
                ans[i][1] = A.at(i);
            } else {
                ans[i][1] = 0;
            }
        }
        res = max( ans[N-2][0], ans[N-1][1] );
    } else {
        int64_t ans[N][3];
        for ( int i = 0; i < N; ++i){
            if ( i >= 2 ){
                ans[i][0] = ans[i-2][0] + A.at(i);
            } else if ( i == 0 ){
                ans[i][0] = A.at(i);
            } else {
                ans [i][0] = 0;
            }
        }
        for ( int i = 0; i < N; ++i){
            if ( i >= 3 ){
                ans[i][1] = max(ans[i-2][1],ans[i-3][0]) + A.at(i);
            } else if ( i == 1 ){
                ans[i][1] = A.at(i);
            } else {
                ans[i][1] = 0;
            }
        }
        for ( int i = 0; i < N; ++i){
            if ( i >= 4 ){
                ans[i][2] = max(ans[i-2][2],max(ans[i-3][1],ans[i-4][0])) + A.at(i);
            } else if ( i == 2 ){
                ans[i][2] = A.at(i);
            } else {
                ans [i][2] = 0;
            }
        }
        
        res = max( ans[N-1][2], max( ans[N-2][1], ans[N-3][0] ));
        
        
        
    }
    
    
    cout << res << endl;
    
    return 0;
}
