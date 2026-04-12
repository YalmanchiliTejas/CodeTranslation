#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;

    while(true){
        std::cin >> n;
        if(n == 0) break;

        int* x = new int[n];

        for(int i=0; i<n; i++){
            std::cin >> x[i];
        }

        std::sort(x, x+n);
        int sum = 0;
        for(int i=1; i<(n-1); i++){
            sum += x[i];
        }

        std::cout << sum/(n-2) << std::endl;

        delete[] x;
    }

    return 0;
}

