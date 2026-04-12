#include <bits/stdc++.h>
#include <set>

using namespace std;

#define lint long long

const lint mod = 1E9 + 7;


int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    multiset<int> Nums;
    for(int i = 0; i < N; ++i){
        auto ItrL = Nums.lower_bound(A[i] - 1);
        auto ItrU = Nums.upper_bound(A[i] - 1);

        if(ItrU == Nums.begin()){
            Nums.insert(A[i]);
        } else{
            Nums.erase(--ItrU);
            Nums.insert(A[i]);
        }

    }
    cout << Nums.size() << endl;
}