#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> A(N,0);
    for(int i=0; i<N; i++) cin >> A[i];

    multiset<int> col;
    for(int a : A){
        auto itr = col.upper_bound(-a);
        if(itr == col.end()){
            col.insert(-a);
            continue;
        }

        col.erase(itr);
        col.insert(-a);
    }
    cout << col.size() << endl;
}
