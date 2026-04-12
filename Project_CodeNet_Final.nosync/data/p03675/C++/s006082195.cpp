typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll n,a[200010];

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if(n==1){
        std::cout << a[0] << std::endl;
        return 0;
    }
    if(n%2==0){
        for (int i = n; i >0; i-=2) {
            std::cout << a[i-1]<<" ";
        }
        for (int i = 1; i <= n-2; i+=2) {
            std::cout << a[i-1]<<" ";
        }
        std::cout << a[n-1 -1] << std::endl;
    }else{
        for (int i = n; i >0; i-=2) {
            std::cout << a[i-1]<<" ";
        }
        for (int i = 2; i <= n-2; i+=2) {
            std::cout << a[i-1]<<" ";
        }
        std::cout << a[n-1 -1] << std::endl;
    }
}
