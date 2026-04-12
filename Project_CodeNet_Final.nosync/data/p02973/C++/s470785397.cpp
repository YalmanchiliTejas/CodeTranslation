#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)
vector<int> Aback;

int binary_search(int A, int cnt){
    int left = 0; int right = cnt + 1;
    while(right - left > 1){
        int mid = (right + left) /2;
        if(Aback[mid] >= A) left = mid;
        else right = mid;
    }
    return right;
}

int main() {
    int N, A, ans, cnt;
    cin>>N;
    Aback.resize(N);
    cnt = 0;

    REP(i, 0, N){
        cin >> A;        
        int j = binary_search(A, cnt);

        Aback[j] = A;
        cnt = max(j, cnt);
    }
    cout << cnt << endl;
}