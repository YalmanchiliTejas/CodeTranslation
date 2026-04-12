#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long int> b(N);
    for(int n=0; n<N; n++) {
        long long int a;
        cin >> a;
        if(n%2) {
            b[N/2-n/2-1]=a;
        } else {
            b[N/2+n/2]=a;
        }
    }
    if(N%2==0) {
        for(int n=0; n<N; n++) {
            cout << b[n] << " ";
        }
    } else {
        for(int n=N-1; n>=0; n--) {
            cout << b[n] << " ";
        }
    }
    cout << endl;


    return 0;
    
}