// atcoder 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int mem = (N-1)/2;
    int n, last;
    if (N%2 == 1) n = N;
    if (N%2 == 0) n = N-1;
    vector<int> ans(n);
    ans[mem] = A[0];
    for(int i=0; i<mem; i++){
        if (i%2 == 0){
            ans[mem+(i+1)] = A[N-1-i];
            ans[mem-(i+1)] = A[N-2-i];
            if(i==mem-1) last = N-3-i;
        }
        else{
            ans[mem+(i+1)] = A[i];
            ans[mem-(i+1)] = A[i+1];
            if(i==mem-1) last = i+2;
        }
    }
    long long answer1 = 0;
    for (int i=0; i<n-1; i++) answer1 += max(ans[i]-ans[i+1], ans[i+1]-ans[i]);
    if (N%2==0) answer1 += max(max(ans[0]-A[last], A[last]-ans[0]), max(ans[n-1]-A[last], A[last]-ans[n-1]));

    ans[mem] = A[N-1];
    for(int i=0; i<mem; i++){
        if (i%2 == 1){
            ans[mem+(i+1)] = A[N-i-1];
            ans[mem-(i+1)] = A[N-i-2];
            if(i==mem-1) last = N-i-3;
        }
        else{
            ans[mem+(i+1)] = A[i];
            ans[mem-(i+1)] = A[i+1];
            if(i==mem-1) last = i+2;
        }
    }
    long long answer2 = 0;
    for (int i=0; i<n-1; i++) answer2 += max(ans[i]-ans[i+1], ans[i+1]-ans[i]);
    if (N%2==0) answer2 += max(max(ans[0]-A[last], A[last]-ans[0]), max(ans[n-1]-A[last], A[last]-ans[n-1]));
    cout << max(answer1, answer2) << endl;
    return 0;
}
