#include <iostream>

namespace Mylib{
    using namespace std;
    
}
int main(void){
    using namespace std;
    int N,A;
    
    cin >> N >> A;
    
    if(N==A){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    
    return 0;
}