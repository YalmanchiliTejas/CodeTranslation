#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;

int N, A[MAX];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    multiset<int> s;
    for(int i=0;i<N;i++){
        auto itr = s.lower_bound(A[i]);
        if(itr == s.begin()){
            s.insert(A[i]);
        } else {
            s.erase(--itr);
            s.insert(A[i]);
        }
    }

    cout << s.size() << endl;
}