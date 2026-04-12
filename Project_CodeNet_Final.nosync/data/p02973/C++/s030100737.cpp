#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
using namespace std;

vector<int> A;
vector<int> B;

int main(){
    int N;
    int saves;
    cin >> N;
    A.resize(N);
    rep(i,N) cin >> A[i];
    reverse(A.begin(), A.end());

    B.push_back(A[0]);
    for(int i=1; i<N; i++){
        auto insrt = upper_bound(B.begin(), B.end(), A[i]);
        auto tmp = insrt-B.begin();
        //cout << tmp << endl;
        if(tmp==B.size()){
            B.push_back(A[i]);
        }else{
            B[tmp] = A[i];
        }
    }
    cout << B.size() << endl;
    return 0;
}