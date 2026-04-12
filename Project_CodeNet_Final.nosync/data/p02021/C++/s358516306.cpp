#include <iostream>
using namespace std;
int main(void){
    long int N, A[101]={}, sum=0, MAX, WORK=0, i, j;
    cin >> N;
    
    for(i=1; i<=N; i++){
        cin >> A[i];
        sum += A[i];
    }
    
    //1日にできる最大の仕事
    MAX = sum / N;
    for(i = MAX; i>=1; i--){
        WORK=0;
        for(j=1; j<=N; j++){
            WORK += A[j];
            if(WORK < i) break;
            WORK -= i;
            if(j == N) break;
        }
        if(j == N) break;
    }
    cout << i << endl;
    return 0;
}

