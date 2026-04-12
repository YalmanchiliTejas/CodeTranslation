#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    long long sum=0,ans=0;
    cin >> N;
    vector<long long> A(N);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
        sum += A.at(i);
    }

    for(int i=0;i<N;i++){
        sum -= A.at(i);
        ans += A.at(i)*(sum%(1000000000+7));
        ans = ans%(1000000000+7);
    }
    cout << ans << endl;
    return 0;

}
