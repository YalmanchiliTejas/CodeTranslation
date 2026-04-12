#include <bits/stdc++.h>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int op_max(int a, int b){
    return max(a,b);
}
int emin(){
    return -1;
}

int target;

bool f(int v) {
     return v < target; }

signed main(){
    int N, Q; cin>>N>>Q;
    vec_int A(N);rep(i,N)cin>>A.at(i);

    segtree<int, op_max, emin> seg(A);

    rep(q, Q){
        int T, a, b;
        cin>>T>>a>>b;
        if(T==1){
            seg.set(a-1,b);
        }else if(T==2){
            cout<<seg.prod(a-1,b)<<endl;
        }else{
            target =  b;
            cout<<seg.max_right<f>(a-1)+1<<endl;
        }

    }


    return 0;
}