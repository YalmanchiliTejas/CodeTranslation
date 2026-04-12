#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    int i;
    int64_t num=0;
    int64_t num2=0;
    int64_t div = pow(10,9) + 7;
    cin >> N;
    vector<int64_t> A(N);
    for(i=0;i<N;i++){
        cin >> A.at(i);
    }

    for(i=0;i<N;i++){
        num += A.at(i);
    }
    num = num % (2*div);
    num = num * num;
    for(i=0;i<N;i++){
        num2 = A.at(i) * A.at(i);
        num2 = num2 % (2*div);
        num = num - num2;
        if(num < 0){
            num += (2*div);
        }
    }
    num = num /2;
    num = num % div;


    cout << num << endl;
}