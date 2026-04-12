#include<bits/stdc++.h>
using ll = long long;
const ll INF_LL = 1000000000000;
#define fir first
#define sec second

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)std::cin >> a[i];
    std::multiset<int> set;
    for(int i = 0; i < n; i++){
        auto itr = set.lower_bound(a[i]);//もしa[i]が小さくて先頭になってしまったら
        if(itr == set.begin()){
            set.insert(a[i]);
        }else{
            itr--;
            set.erase(itr);
            set.insert(a[i]);
        }
    }
    std::cout << set.size() << std::endl;
}
