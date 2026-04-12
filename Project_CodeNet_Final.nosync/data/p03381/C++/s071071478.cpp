#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<thread>
#include<future>
using namespace std;

#define INF 1e15+7
typedef long long ll;



int main(){
    int N;
    cin>>N;
    vector<ll>X(N);
    vector<ll>vec(N);
    for(int i=0;i<N;i++){
        cin>>X[i];
        vec[i]=X[i];
    }
    sort(vec.begin(),vec.end());
    vector<ll>B(N);
    ll l = vec[N/2-1];
    ll r = vec[N/2];
    for(int i=0;i<N;i++){
        if(X[i]<=l){
            B[i]=r;
        } else if(X[i]>=r){
            B[i]=l;
        }
        cout<<B[i]<<endl;
    }
    
}
