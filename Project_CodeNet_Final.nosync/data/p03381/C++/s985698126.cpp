#include<iostream>
#include<algorithm>
using namespace std;

using lint = long long int;

int main(){
    lint N,A[200002],B[200002];
    lint temp;

    cin >> N;
    for(lint i=0;i<N;i++){
        cin >> temp;
        A[i] = temp;
        B[i] = temp;
    }
    sort(B,B+N);

    lint left = B[N/2 - 1];
    lint right = B[N/2];

    for(lint i=0;i<N;i++){
        if(A[i]<=left){
            cout << right << "\n";
        }
        else{
            cout << left << "\n";
        }
    }
    
    return 0;
}