#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
constexpr int mo = 1e9+7;
constexpr int  mod = mo;
constexpr ll inf = 1ll<<62;

int main(){
    int n;
    cin>>n;
    multiset<int> s;
    for(int i=0;i<n;++i){
        int a;cin>>a;
        auto it = s.lower_bound(a);
        if(s.begin() == it){
            s.insert(a);
        }else{
            it--;
            s.erase(it);
            s.insert(a);
        }
    }
    cout << s.size() << endl;
    return 0;
}

