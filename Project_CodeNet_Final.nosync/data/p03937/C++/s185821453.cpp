typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
ll h,w;
string a[10];
ll cnt = 0;
ll saiki(ll x, ll y,ll now){
    bool ok = false;
    if(x==w-1 && y==h-1&& now == cnt){
        return true;
    }
    if(x<w-1){
        if(a[y][x+1] == '#'){
            ok = ok || saiki(x+1,y,now+1);
        }
    }
    if(y<h-1){
        if(a[y+1][x] == '#'){
            ok = ok || saiki(x,y+1,now+1);
        }
    }
    return ok;
}
int main() {
    
    std::cin >> h>>w;
    
    for (int i = 0; i < h; i++) {
        std::cin >> a[i];
        for (int j = 0; j < w; j++) {
            if(a[i][j] == '#')cnt++;
        }
    }
    if(saiki(0,0,1)){
        std::cout << "Possible" << std::endl;
    }else{
        std::cout << "Impossible" << std::endl;
    }
}
