#include<iostream>

using namespace std;

int N;
int A[30];

int  main() {
    cin >> N;
    for(int i = 0;i < N;i++) cin >> A[i];
    int total = 0;

    bool flag = false;

    for(int i = 0;i < N;i++){
        flag = false;
        for(int j = 0; j < i; j++){
            if(A[i] < A[j]){
                flag = true;
            }
        }
        if(!flag){
            total++;
        }
    }

    cout << total << endl;
}