#include<bits/stdc++.h> 
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int i = 0; i < N; i++)

template<class T> 
void dbg_vector(const vector<T>& v){
    for(const T& a : v){
        cout << a << " ";
    }
    cout << '\n';
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    reverse(A.begin(), A.end());

    vector<int> vec;
    for(const auto& a : A){
        if(vec.size() == 0) {
            vec.emplace_back(a);
            continue;
        }

        auto it = upper_bound(vec.begin(), vec.end(), a);
        if(it == vec.end()) vec.emplace_back(a);
        else *it = a;
    }

    cout << vec.size() << endl;
}
