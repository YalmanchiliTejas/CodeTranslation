typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

struct xy{
    ll x;
    ll y;
};

bool asc( const xy& left, const xy& right ) {
     return left.x < right.x;
 }

int main() {
    ll n;
    xy xys[200001];
    std::cin >> n;
    ll f_r_max,f_r_min,f_b_max,f_b_min;
    f_r_max = 0;
    f_r_min = 1000000000+10;
    f_b_max = 0;
    f_b_min = 1000000000+10;
    
    ll result = 0;
    
    for (int i = 0; i < n; i++) {
        ll tmp_x,tmp_y;
        std::cin >> tmp_x >>tmp_y;
        
        xys[i].x = min(tmp_x,tmp_y);
        xys[i].y = max(tmp_x,tmp_y);
         
        f_r_max = max(f_r_max, xys[i].y );
        f_r_min = min(f_r_min, xys[i].y );
        f_b_max = max(f_b_max, xys[i].x );
        f_b_min = min(f_b_min, xys[i].x );
    }
    
    result = (f_r_max - f_r_min) * (f_b_max - f_b_min);
    
    sort(xys,xys+n,asc);
    
    ll now_min = 1000000000+10;
    ll now_max = f_b_max;
    
    // if(xys[0].y > now_max){
    //     if(xys[0].y - xys[1].x < now_max - now_min){
    //         now_max = xys[0].y;
    //         now_min = 
    //     }
    // }else{
    //     now_min = xys[0].y;
    // }
    
    // チェンジできなくなったらそこで試合終了
    
    for (int i = 0; i < n; i++) {
        if( xys[i].y >now_max ){
            if(now_min == 1000000000+10){
                result = min(result, ( f_r_max - f_b_min) * (now_max-xys[i].x));
                
                now_max = xys[i].y;
            }else{
                // 交換　の利益が上回る
                if(xys[i].y - now_min < now_max - min(now_min,xys[i].x)){
                    now_max = xys[i].y;
                }else{
                    // 交換不可能！試合終了
                    now_min = min(now_min,xys[i].x);
                    break;
                }
            }
        // 無条件でチェンジ可能
        }else {
            now_min = min(now_min,xys[i].y);
            
        }
    }
    
    // std::cout << now_max << std::endl;
    // std::cout << now_min << std::endl;
    
    if(now_min ==1000000010 ){
        std::cout << result << std::endl;
        return 0;
    }
    
    
    std::cout << min(result, ( f_r_max - f_b_min) * ( now_max - now_min) ) << std::endl;
}
