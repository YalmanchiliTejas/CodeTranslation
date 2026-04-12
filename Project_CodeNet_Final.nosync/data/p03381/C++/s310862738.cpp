#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    int N; cin>> N;
    vector<int> A(N);
    vector<int> X;
    for(int i=0; i<N; i++){
    cin >> A.at(i);
    X.push_back(A.at(i));
    }
    X.push_back(-1);

    sort(X.begin(),X.end());
    int l = X.at(N/2);
    int r = X.at(N/2+1);

    for(int i=0; i<N; i++){
        if(A.at(i) >= r ){
            cout << l << endl;
        }else{
            cout << r << endl;
        }
    }
    
}