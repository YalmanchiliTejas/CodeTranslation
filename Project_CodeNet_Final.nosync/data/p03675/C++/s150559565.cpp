#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<unordered_set>
using namespace std;

typedef long long ll;

#define FOR(i,N) for(int i=0;i<N;i++)

int mod=1e9+7;



int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b;
    int i;
    for(i=n;i>0;i-=2){
        b.push_back(a[i-1]);
    }
    if(i==0){
        i=1;
    } else {
        i=2;
    }
    for(;i<n;i+=2){
        b.push_back(a[i-1]);
    }
    for(auto x:b){
        cout<<x<<" ";
    }
    cout<<endl;
}
