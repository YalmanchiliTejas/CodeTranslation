typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll paty(ll i){
    return (ll)pow(2,i+1)-1;
}

ll all(ll i){
    return (ll)pow(2,i+2)-3;
}
ll midle(ll i){
    return (ll)pow(2,i+1)-1;
}

int main() {
    ll n,x;
    std::cin >> n>>x;
    
    ll result = 0;
    for (int i = n; i >= 0; i--) {
        if( x == all(i) ){
            result += paty(i);
            break;
        }
        
        if( x == 1 ){
            break;
        }
        
        if( x > midle(i) ){
            result += paty(i-1)+1;
            x -= midle(i);
        }else if(x < midle(i)){
            x--;
            continue;
        }else{
            result += paty(i-1)+1;
            break;
        }
    }
    std::cout << result << std::endl;
}