#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
#include<map>
#include<set>
#include <climits>
using namespace std;
#define INF 1100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;



int main(){
    int N;
    cin>>N;
    ll a;
    vector<ll> V;
    V.push_back(1);
    for(int i=0;i<N;i++){
        cin>>a;
        a*=(-1);
        int x=upper_bound(V.begin(),V.end(),a)-V.begin();
        if(V[x]==1){
            V[x]=a;
            V.push_back(1);
        }
        else V[x]=a;
    }
    cout<<(int)(V.size()-1)<<endl;
}
