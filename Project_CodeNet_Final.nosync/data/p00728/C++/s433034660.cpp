#include <iostream>
using namespace std;



int main(){
    int N;
    int A[100]={0};
    while (cin >> N && N!=0) {
        int mi_num=10000,ma_num=-1,ave=0,sum=0;
        for (int i=0; i<N; i++) cin >> A[i];
        for (int i=0; i<N; i++) {
            mi_num=min(mi_num,A[i]);
            ma_num=max(ma_num,A[i]);
            sum+=A[i];
        }
        ave=(sum-mi_num-ma_num)/(N-2);
        cout << ave << endl;
    }
}

