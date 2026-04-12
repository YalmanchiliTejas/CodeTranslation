#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    long long int a;
    cin>>n;
    std::deque<long long int> deq;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    std::deque<long long int> S(n+1,0);
    for (int i=0;i<n;i++) {
        S[i+1]=S[i]+deq[i];
    }
    long long int sum=0;
    for (int i=1;i<=n;i++) {
        sum+=(deq[i-1]%1000000007*((S[n]-S[i])%1000000007))%1000000007;
    }
    cout<<sum%1000000007<<endl;
}