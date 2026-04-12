#include <iostream>
using namespace std;
//B - Great Ocean View
int main(void){
    int n;
    std::cin >> n;
    int maxH=0;
    int cnt=0;
    for (int i = 0; i < n; i++) {
        int h;
        std::cin >> h;
        if(maxH<=h){
            maxH=h;
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
    
}
