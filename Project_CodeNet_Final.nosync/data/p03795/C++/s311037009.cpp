#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,l,n) for(int i=(l);i<(n);i++)

template<class T>
using vi = vector<T>;
template<class T>
using vvi = vector<vector<T>>;

int main(){
    int N;
    cin >> N;
    cout << N*800-N/15*200 << endl;
    return 0;
}