#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++){    ;
int main() {
int N;
cin>>N;
int max=0;
int answer=0;
vector<int>H(N);
rep(i,N)
cin>>H.at(i);
if(max<=H.at(i)){
    answer++;
    max=H.at(i);
}
}
cout<<answer<<endl;
 }
