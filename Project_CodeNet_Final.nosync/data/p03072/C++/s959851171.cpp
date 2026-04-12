#include <iostream>
int main(){
    int n;
    int cnt = 1;
    std::cin >> n;
    int v[n];
    for(int i=0; i<n; ++i){
        std::cin >> v[i];
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(v[j] > v[i]){
                break;
            }else{
                if(j == (i-1)){
                    cnt++;
                }
            }
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}