#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include<set>
#include<bitset>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
#define put(n) cout<<(n)<<"\n"
#define FOR(i,num,N) for(int(i)=(num);(i)<(N);++(i))
#define RFOR(i,num,N) for(int (i)=(num);(i)>(N);--(i))
#define all(v) (v).begin() , (v).end()
#define rall(v) (v).rbegin() , (v).rend()

int main(){
    int N,left,right;
    cin>>N;
    vector<int> T(N);
    FOR(i,0,N) cin>>T[i];

    left = T[0]/10;
    for(int i=1;left>=i&&i<N;++i){
        left = max(left,T[i]/10+i);
    }

    reverse(T.begin(),T.end());

    right = T[0]/10;
    for(int i=1;right>=i&&i<N;++i){
        right = max(right,T[i]/10+i);
    }

    if(left>=N-1 && right>=N-1) cout<<"yes\n";
    else cout<<"no\n";

}
