#include <bits/stdc++.h>
using namespace std;
//関数
const long INF=1000000000000000;

int main(void){
    long N;
    cin>>N;
    vector<long> A(N);
    for(int i=0;i<N;i++) cin>>A.at(i);
    
    multiset<long> s;
    auto ite=s.begin();
    for(int i=N-1;i>=0;i--){
        ite=s.upper_bound(A.at(i));
        if(ite==s.end()) s.insert(A.at(i));
        else{
            s.erase(ite);
            s.insert(A.at(i));
        }
    }
    
    cout<<s.size()<<endl;
}

