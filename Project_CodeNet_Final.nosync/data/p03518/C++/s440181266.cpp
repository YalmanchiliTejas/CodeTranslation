#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
        B[i] = A[i];
    }

    vector<int> ans;
    for(int i=0; i<N-1; i++){
        ans.push_back(1);
        rotate(A.begin(), A.begin()+1, A.end());
        for(int j=0; j<N-1; j++){
            if(A[0] < A.back()){
                ans.push_back(N-1);
                swap(A[0], A.back());
            }
            ans.push_back(1);
            rotate(A.begin(), A.begin()+1, A.end());
        }
    }

    cout << ans.size() << endl;
    for(int a : ans) cout << a << endl;

    // for(int a : ans){
    //     for(int i=a; i<N; i++) swap(B[i], B[i-a]);
    // }
    // for(int i=0; i<N; i++) cerr << B[i] << " ";
    return 0;
}
