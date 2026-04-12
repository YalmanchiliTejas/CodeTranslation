#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //GCC5.4.1で配列の範囲外アクセスをエラーにする

// https://atcoder.jp/contests/abc177/editorial/82

//cmdで g++ test.cpp とするとコンパイルできる
//制限1秒なら10^6は余裕 10^7は多分間に合う 10^8はよほど単純でないと厳しい

#define ALL(x) x.begin(),x.end()
#define get_tp(t,i) get<i>(t)
typedef long long ll; //long long
typedef pair<int,int> pii; //pair<int,int>
typedef pair<long long,long long> pllll; //pair<long long,long long>
typedef vector<int> vi; //vector<int>
typedef vector<vector<int>> vvi; //vector<vector<int>>
typedef vector<ll> vll; //vector<long long>
typedef vector<vector<ll>> vvll; //vector<vector<long long>>
typedef priority_queue<int, vector<int>, greater<int> > gpq; //逆順priority_queue
typedef priority_queue<int> pq;

//const int MOD=998244353;
const int MOD=1000000007; //10^9+7
const long double PI=3.1415926535897932;

int main(){
    int H,W;cin>>H>>W;
    vvi A(H,vi(W));
    vector<bool> H_ok(H,false),W_ok(W,false);
    for(int h=0;h<H;h++){
        string S;cin>>S;
        for(int w=0;w<W;w++){
            A[h][w]=S[w];
            if(S[w]=='#'){
                H_ok[h]=true;W_ok[w]=true;
            }
        }
    }
    for(int h=0;h<H;h++){
        if(!H_ok[h])continue;
        for(int w=0;w<W;w++){
            if(!W_ok[w])continue;
            cout<<(char)A[h][w];
        }
        cout<<endl;
    }
}