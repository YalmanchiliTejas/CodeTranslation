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

template<typename... T>
void write_space(T... a){
    ((cout << a << " "),...);
}


void solve(){
    int x;
    read(x);
    if( x >= 30){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
} 

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
