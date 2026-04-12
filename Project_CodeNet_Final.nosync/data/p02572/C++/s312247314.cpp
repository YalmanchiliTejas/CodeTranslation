#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007

int main(){
    int N;
    int64_t result=0,sum=0;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
        sum+=A.at(i);
    }
    for(int i=0;i<N;i++){
        sum-=A.at(i);
        result+=(sum%INF)*A.at(i);
        result%=INF;
    }
    cout<<result<<endl;
}
