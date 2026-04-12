#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;

int main(){
    ll N; cin >> N;
    vector<ll> A(N);
    multiset<int> T;
    int cnt = 1;
    for(int i = 0; i < N; i++){
        cin >>A[i];
    }
    T.insert(A[0]);
    T.insert(INF);
    for(int i = 1; i < N; i++){
        if(*T.begin() >= A[i]) T.insert(A[i]);
        else{
            auto past = T.begin();
            auto it = T.lower_bound(A[i]);
            it--;
            T.erase(it);
            T.insert(A[i]);
            /*for(auto it = T.begin(); it != T.end(); it++){
                //cout << i << " " << *it << endl;
                if(*it >= A[i]){
                    T.erase(past);
                    T.insert(A[i]);
                    break;
                }
                past = it;
            }*/
        }
        /*cout << i << " ";
        for(auto it1 = T.begin(); it1 != (T.end()++); it1++) cout << " " << (*it1);
        cout << endl;*/
    }
    cout << T.size() - 1 << endl;
}