#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#define INF 100000000
#define MOD 1000000007
using namespace std;


int main(){
    int N;
    cin >> N;
    
    long long X[N];
    for(int i=0; i<N; i++){
        cin >> X[i];
    }
    
    
    long long B[N];
    
    pair<long long , int> p[N];
    for(int i=0; i<N; i++){
        p[i].first=X[i];
        p[i].second=i;
    }
    
    sort(p,p+N);
    
    for(int i=0; i<N/2; i++){
        B[p[i].second]=p[N/2].first;
    }
    
    
    for(int i=N/2; i<N; i++){
        B[p[i].second]=p[N/2-1].first;
    }
    

    for(int i=0; i<N; i++){
        cout<<B[i]<<endl;
    }
    
    return 0;
}
