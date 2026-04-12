#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

int main() {

    ll N;
    vector<ll> A;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        A.push_back(a);
    }

//    for (int i = 0; i < N; ++i) {
//       ll b = A[i];
//        cout << A[i];
//    }
//    cout << " " << endl;
    sort(A.begin(),A.end());

    //tekito 2つめを最大にして、後最大差分をえらんで、残った数字を先頭にいれて数えればいい？

    vector<ll> B;
    int j =0;
    for (int i = 0; i < N; ++i) {
        j++;
        ll a  = A[N-1-i];
        if(j == N){
            B.insert(B.begin(),a);
            break;
        }
        B.push_back(a);
        j++;
        ll a2 = A[i];
        if(j == N){
            B.insert(B.begin(),a2);
            break;
        }
        B.push_back(a2);
    }

//    for (int i = 0; i < N; ++i) {
//        ll b = B[i];
//        cout << B[i];
//    }
//    cout << " " << endl;
    ll r = 0;
    ll bf = B[0];
    for (int i = 1; i < N; ++i) {
        ll b = B[i];
        r += abs(b - bf);
        bf = b;
    }

    vector<ll> C;
    j =0;
    for (int i = 0; i < N; ++i) {
        j++;
        ll a2 = A[i];
        if(j == N){
            C.insert(C.begin(),a2);
            break;
        }
        C.push_back(a2);
        j++;
        ll a  = A[N-1-i];
        if(j == N){
            C.insert(C.begin(),a);
            break;
        }
        C.push_back(a);
    }

//    for (int i = 0; i < N; ++i) {
//        ll b = B[i];
//        cout << B[i];
//    }
//    cout << " " << endl;
    ll r2 = 0;
    ll bf2 = C[0];
    for (int i = 1; i < N; ++i) {
        ll b = C[i];
        r2 += abs(b - bf2);
        bf2 = b;
    }
    ll r3 = (r > r2)? r : r2;
    cout << r3 << endl;

    return 0;
}