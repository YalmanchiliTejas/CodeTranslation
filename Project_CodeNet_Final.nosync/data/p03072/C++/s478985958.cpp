#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;
    int m,ans=0;
    std::cin >>n ;
    int h;
    for (int i=0;i<n;i++){
        std::cin >>h;
        if (m<=h){
            m=h;
            ans++;
        }
    }
    std::cout << ans << std::endl;
    //else std::cout << 2*max(a,b)-1 << std::endl;
}
