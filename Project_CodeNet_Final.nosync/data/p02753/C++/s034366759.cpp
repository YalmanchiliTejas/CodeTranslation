#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0; (i)<(n); (i)++)
#define repr(i,n) for(int (i)=(n); (i)>=0; (i)--)

const ll MOD = 1e9+7;
const int INF = (int)1e9+7;

// vector<tuple<long,long>> items; // (value, weight)
// auto item = items[i];
// long v = get<0>(item);
// long w = get<1>(item);
// long v, w;
//   for( int i = 0; i < N; i++ ){
//     cin >> v >> w;
//     items.push_back( make_tuple(v, w) ); // item : (value, weight)
//   }

int main(){
    string S;
    cin >> S;
    if(S=="AAA" || S=="BBB") cout << "No";
    else cout << "Yes";
}