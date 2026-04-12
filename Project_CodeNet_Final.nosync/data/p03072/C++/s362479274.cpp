#include <iostream>
using namespace std;

int N;
int A[21];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    int max=0;
    int res=0;
    
    
    for (int i = 0; i < N; ++i) {
            if (A[i] >=max){
            max=A[i];
            res++;
            }
        }
    
    cout << res << endl;
    
    }