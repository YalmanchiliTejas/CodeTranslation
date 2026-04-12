#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int z;
    cin>>z;
    if(z-3==0 || z-5==0 || z-7==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}