#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    deque<long long> dq, dq2;
    dq.push_back(A[0]);
    int i = 1;
    int ind = N - 1;
    int j = 0;
    while(i <= ind){
        if(j % 2 == 0){
            if(ind - i == 0){
                if(abs(A[ind] - dq.front()) > abs(A[ind] - dq.back())) dq.push_front(A[ind]);
                else dq.push_back(A[ind]);
                ind--;
            }
            else{
                dq.push_back(A[ind]);
                ind--;
                dq.push_front(A[ind]);
                ind--;
            }
        }
        else{
            if(ind - i == 0){
                if(abs(A[i] - dq.front()) > abs(A[i] - dq.back())) dq.push_front(A[i]);
                else dq.push_back(A[i]); 
                i++;
            }
            else{
                dq.push_back(A[i]);
                i++;
                dq.push_front(A[i]);
                i++;
            }
        }
        j++;
    }
    dq2.push_back(A[N - 1]);
    i = 0;
    ind = N - 2;
    j = 1;
    while(i <= ind){
        if(j % 2 == 0){
            if(ind - i == 0){
                if(abs(A[ind] - dq2.front()) > abs(A[ind] - dq2.back())) dq2.push_front(A[ind]);
                else dq2.push_back(A[ind]);
                ind--;
            }
            else{
                dq2.push_back(A[ind]);
                ind--;
                dq2.push_front(A[ind]);
                ind--;
            }
        }
        else{
            if(ind - i == 0){
                if(abs(A[i] - dq2.front()) > abs(A[i] - dq2.back())) dq2.push_front(A[i]);
                else dq2.push_back(A[i]); 
                i++;
            }
            else{
                dq2.push_back(A[i]);
                i++;
                dq2.push_front(A[i]);
                i++;
            }
        }
        j++;
    }
    long long ans = 0;
    long long temp = dq.front();
    dq.pop_front();
    while(!dq.empty()){
        long long res = dq.front();
        dq.pop_front();
        ans += abs(res - temp);
        temp = res;
    }
    temp = dq2.front();
    dq2.pop_front();
    long long ans2 =0;
    while(!dq2.empty()){
        long long res = dq2.front();
        dq2.pop_front();
        ans2 += abs(res - temp);
        temp = res;
    }
    cout << max(ans, ans2) << endl;
}