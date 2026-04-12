#include <iostream>

using namespace std;

int main(){
    int N, a, b, sum = 1;
    cin >> N;
    cin >> a;
    
    for(int i = 0;i<(N-1);i++){
        cin >> b;
        if(b >=a){
            sum++;
            a = b;
        }
    }
    cout << sum <<endl;
    
    return 0;
}