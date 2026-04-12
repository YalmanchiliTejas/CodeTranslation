#include <bits/stdc++.h>

using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
const ll INF = 1001001000100010;
const ld PI = 3.14159265358979323846;


int main() {
// 入力
    int N,M; 
    cin >> N>>M;
    vector<pair<int,int>> path(M);
    rep(i,M){
        cin>>path[i].first>>path[i].second;
    }
    


    // 初期順列
    vector<int> order(N+1);
    rep3(i,N) order[i] = i;

    int count=0;
    bool judge_all;
    bool judge[10];


    // 探索
    
    do {
        if(order[1]!=1){
            continue;
        }
        judge_all=true;
        rep4(i,2,N){
            judge[i]=false;
        }
        rep(i,M){
            rep4(j,2,N){
            if(((path[i].first==order[j-1])&&(path[i].second==order[j]))||((path[i].first==order[j])&&(path[i].second==order[j-1]))){
                judge[j]=true;
            }
            }

        }
        rep4(i,2,N){
            if(!judge[i]){
                judge_all=false;

            }
        }
        if(judge_all){
            count++;
        }

        
    } while (next_permutation(order.begin(), order.end()));

    // 答えを出力
    cout << count << endl;
return 0;
}

