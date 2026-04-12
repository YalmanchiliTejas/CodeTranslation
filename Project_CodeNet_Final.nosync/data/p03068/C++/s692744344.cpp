#include <iostream>
#include <vector>
int main(){
    int n, k;
    char a;
    std::cin >> n;
    std::vector <char> v(n);
    for(int i=0; i<n; i++){
        std::cin >> v[i];
    }
    std::cin >> k;
    a = v.at(k-1);
    for(int i=0; i<n; ++i){
        if(a != v[i]){
            std::cout << "*";
        }else{
            std::cout << v[i];
        }
    }
    std::cout << "\n";
    return 0;
}