#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
typedef long long ll;

void printV(vector<ll> v){
    cout << "[vector]" << endl;
    int n = v.size();
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void add_to_C(vector<ll>& C, ll val, int num){
    for(int i=0; i<num; i++){
        C.push_back(val);
    }
}

ll calc_sum(vector<ll> C, vector<ll> A){
    ll sum = 0;
    int n = C.size();

    for(int i=0; i<n; i++){
        sum += C[i] * A[i];
    }
    return sum;
}

void minus_descend(vector<ll>& C){
    int n = C.size();
    for(int i=0; i<n; i++){
        C[i] *= -1;
    }
    sort(C.begin(), C.end(), std::greater<ll>());
}

int main(){
    // input
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    sort(A.begin(), A.end(), std::greater<ll>()); // descending

    ll sumMax = 0;
    /*
    if(N==2){
        sumMax = abs(A[0] - A[1]);
        cout << sumMax << endl;
        return 0;
    }
    */

    vector<ll> C(0); // coefficient array, always descending
    
    if(N%2 == 1){
        // from upper
        ll minus_two_num = (N - 2 + 1) / 2;
        ll plus_two_num = N - 2 - minus_two_num;
        add_to_C(C, 2, plus_two_num);
        add_to_C(C, 1, 2);
        add_to_C(C, -2, minus_two_num);
        sumMax = calc_sum(C, A);

        // from lower
        minus_descend(C);
        ll sumMax2 = calc_sum(C, A);

        sumMax = max(sumMax, sumMax2);
    }
    else{
        // from upper
        ll minus_two_num = (N - 2) / 2;
        ll plus_two_num = (N - 2) / 2;
        add_to_C(C, 2, plus_two_num);
        add_to_C(C, 1, 1);
        add_to_C(C, -1, 1);
        add_to_C(C, -2, minus_two_num);
        sumMax = calc_sum(C, A);

        // from lower
        minus_descend(C);
        ll sumMax2 = calc_sum(C, A);

        sumMax = max(sumMax, sumMax2);        
    }

    // output
    cout << sumMax << endl; 
    
    return 0;
}