#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    ll r,g,b;
    std::cin >> r>>g>>b;
    string ans = ( (10*g+b)%4 == 0 ) ? "YES" : "NO";
    std::cout << ans << std::endl;
}
