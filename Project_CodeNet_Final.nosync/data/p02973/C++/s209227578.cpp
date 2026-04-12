#include<bits/stdc++.h>
#include<boost/container/flat_set.hpp>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;

    boost::container::flat_multiset<unsigned long, greater<>> s;
    unsigned long ans{0};
    for(unsigned long i = 0, A; i < N; ++i){
        cin >> A;
        auto it = s.upper_bound(A);
        if(it != s.end()){
            s.erase(it);
        }else{
            ++ans;
        }
        s.insert(A);
    }
    cout << ans << endl;
}