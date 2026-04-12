#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

int main(){
    int N;cin>>N;
    vec A(100010);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    deque<ll> dq;
    dq.push_back(A[0]);
    for(int i=1;i<N;i++){
        if(dq[dq.size()-1]<A[i]){
            dq[dq.size()-1]=A[i];
        }
        else if(A[i]<=dq[0]){
            dq.push_front(A[i]);
        }
        else{
            auto itr=lower_bound(dq.begin(),dq.end(),A[i]);
            itr--;
            *itr=A[i];
        }
    }
    cout<<dq.size()<<endl;
    return 0;
}