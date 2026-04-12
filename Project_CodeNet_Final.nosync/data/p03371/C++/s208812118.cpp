#include <bits/stdc++.h>
//#define DEBUG
#define REP(i, nn ) for(int i = 0 ; i < (int) nn; i++)
#define deb(x) std::cout << #x << " " << x << endl;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename... T>
void read(T& ... a){
    ((cin >> a),...);
}
template<typename... T>
void write(T... a){
    ((cout << a << "\n"),...);
}

void solve(){
    int a, b, c, x, y;
    read(a, b, c, x, y);
    int min_cost = a * x + b * y;
    for(int z = 0; z <= max(x,y) * 2; z++){
        int cost = a * max(x - z /2, 0) + b * max(y - z/2, 0) + c * z;
        if( cost < min_cost){
            min_cost = cost;
        }
    }
    write(min_cost);
} 

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}

//Thanks to CSES problemset
// I am trained with this kind of problem