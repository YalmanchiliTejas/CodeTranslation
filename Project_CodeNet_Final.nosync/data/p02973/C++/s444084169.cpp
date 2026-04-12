typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    multiset<ll> ms;
    ll n;
    ll a[100010];
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        auto itr = ms.lower_bound(a[i]);
        // --index;
        if(itr == ms.begin()){
            ms.insert(a[i]);
        }else{
            itr--;
            itr = ms.erase(itr);       //  削除
            ms.insert(a[i]);
        }
    }
    // for (auto e : ms) {
    //     std::cout << e << std::endl;
    // }
    std::cout << ms.size() << std::endl;
    
}


