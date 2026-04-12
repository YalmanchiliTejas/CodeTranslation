#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    deque<ll> v;
    ll N,n;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> n;
        auto itr = lower_bound(v.begin(),v.end(),n);
        if(v.begin() == itr){
            v.push_front(n);
            continue;
        }
        *(itr-1) = n;
    }
    cout << v.size() << endl;
    return 0;
}