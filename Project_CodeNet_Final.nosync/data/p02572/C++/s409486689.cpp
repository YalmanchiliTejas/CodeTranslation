#include <iostream>
#include <vector>
using namespace std;

typedef long long ullong;

int main(void){
    // Your code here!
    int N;
    cin >> N;
    vector<int> A(N);
    ullong Asum = 0;
    for(int i=0;i<N;i++){
        cin >> A.at(i);
        Asum += A.at(i);
        Asum %= 1000000007;
    }
    
    ullong sum = 0;
    for(int i=0;i<N-1;i++){
        Asum -= A.at(i);
        if(Asum<0) Asum += 1000000007;
        sum += (A.at(i)*Asum);
      	sum %= 1000000007;
    }
    cout << sum%1000000007 << endl;
}
