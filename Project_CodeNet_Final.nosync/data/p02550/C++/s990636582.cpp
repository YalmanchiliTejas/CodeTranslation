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
    ll n, x, m;
    read(n,x,m);
    map<ll,int> mp; 
    ll cur_term = x;
    ll sum = x; 
    int count = 1;
    int i;
    for( i = 1 ; i < n ; i++){
       cur_term = cur_term * cur_term; 
       if(cur_term >= m){
           cur_term = cur_term % m;
       }
       if(mp.find(cur_term) != mp.end()){
           break;
       }else{
           mp[cur_term]++;
       }
       sum += cur_term;
       count++;
    }
    if( i == n){
        cout  << sum << endl;
        return;
    }
    // deb(sum);
    ll period_sum = 0;
    ll period_term = cur_term;
    int period = 0;
    do{
        period++;
        period_sum += cur_term;
        cur_term = cur_term * cur_term;
        if(cur_term >= m){
            cur_term = cur_term % m;
        }
    }while(cur_term != period_term);
    n -= count;
    // deb(period);
    // deb(n);
    ll period_num = n / period;
    ll remain = n % period;
    sum += period_num * period_sum;
    cur_term = period_term;
    for(i = 0 ; i < remain ; i++){
       sum += cur_term; 
       cur_term = cur_term * cur_term;
       if(cur_term >= m){
           cur_term = cur_term % m;
       }
    }
    cout << sum << endl;
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/
    solve();
    return 0;
}

