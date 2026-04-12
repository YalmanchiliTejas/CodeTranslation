#include <bits/stdc++.h>
#define rep(i,n)    for(int i=0;i< (n);i++)
using namespace std;
using P = pair<int,int>;

int main() {
    int N;
    cin>>N;
    vector<int> A(N);
    int mod = 1000000007;
    long long sum = 0;
    long long temp = 0;

    for(int i=0;i<N;i++){
        cin>>A[i];
        temp += A[i];
        temp %= mod;
    }
    

    for(int i=0;i<N;i++){
        temp -= A[i];
        if(temp<0)  temp += mod;
        sum += A[i] * temp;
        sum %= mod;
    }

    cout<<sum<<endl;

    return 0;
}