#include<iostream>
#include<cstdio>
using namespace std;

int N;
long long a[50];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    bool complete = false;
    long long ans = 0;
    while(!complete){
        long long s[50] = {}, s_sum = 0;
        for(int i = 0; i < N; i++){
            s[i] = a[i] / N;
            a[i] -= s[i] * N;
            s_sum += s[i];
        }
        complete = true;
        for(int i = 0; i < N; i++){
            a[i] += (s_sum - s[i]);
            if(a[i] >= N){
                complete = false;
            }
        }
        ans += s_sum;
    }
    cout << ans << endl;
}