#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<P> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());

    vector<int> ans(N);
    for(int i=0;i<N;i++){
        ans[A[i].second] = i < N / 2 ? A[N / 2].first : A[N / 2 - 1].first;
    }

    for(int a : ans){
        cout << a << endl;
    }

    return 0;
}