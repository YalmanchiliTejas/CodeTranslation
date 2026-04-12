#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    long long int count=0;
    int a, b=K+1;
    while(b<=N) {
        a = K;
        // cout << "b = " << b << endl;
        // cout << count << " -> ";
        if(K==0) {
            count += N;
        } else {
            if(b-a-1>(N-a)%b) {
                count += ((N-a)/b+1)*((N-a)%b+1);
                count += ((N-a)/b)*((b-a)-(N-a)%b-1);
            } else {
                count += ((N-a)/b+1)*(b-a);
            }
        }
        // cout << count << endl;
        // while(a<b) {
        //     if(a==0) {
        //         count += (N-a)/b;
        //     } else {
        //         count += (N-a)/b+1;
        //     }
        //     a++;
        // }
        
        b++;
    }
    
    cout << count << endl;
    
    return 0;
    
}