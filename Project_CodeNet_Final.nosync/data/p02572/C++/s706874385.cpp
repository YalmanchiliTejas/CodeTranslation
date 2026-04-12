#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v.at(i);
    }

    long long sum = 0;
    for(int i = 0; i < N; i++){
        sum += v.at(i);
    }

    long long int psum = 0;
    for(int i = 0; i < N-1; i++){
        sum -= v.at(i);
        psum += v.at(i)*(sum%1000000007LL);
        psum %= 1000000007LL;
    }
    cout << (long long)psum << endl;
}