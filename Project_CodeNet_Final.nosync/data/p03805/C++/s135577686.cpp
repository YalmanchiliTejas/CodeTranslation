#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

using llint = long long int;

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr long long int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

class Graph{
public:
    ////////////グラフサイズを渡して作成する
    ////////////infの値は必要に応じて調整すること
    Graph(long long int n):g_size(n),edges(n,vector<long long int>(n,inf)){
        REP(i,n){
            edges[i][i] = 0;
        }


    }
    
    //////////// 枝のvector<>をわたして作成
    //////////// infの値は必要に応じて調整すること
    Graph(long long int n,vector<pair<long long int,long long int>> v):g_size(n),edges(n,vector<long long int>(n,inf)){
        REP(i,g_size){
            edges[i][i] = 0;
        }
        REP(i,v.size()){
            add_edge(v[i].first, v[i].second);
        }        
    }

    ///////////初期状態では有向
    ///////////無向にするときは
    /*  edges[b][a] = cost;  */
    //を追加
    void add_edge(long long int a,long long int b,long long int cost=1){
        edges[a][b] = cost;
        edges[b][a] = cost;
    }
      llint solve(){
        llint result = 0;
        result += search(0,1<<0);
        return result;
    }
    llint search(llint n,llint bit){
        if(bit==(1<<g_size)-1){
            return 1;
        }
        llint result = 0;
        REP(i,g_size){
            if(edges[n][i]!=1||((1<<i)&bit)){
                continue;
            }else if(((bit | (1 << i)))==(1<<g_size)-1){
                    return 1;
            }else{
                result += search(i, (bit | (1 << i)));
            }
        }
        return result;
    }
  

  
private:
    long long int g_size;
    vector<vector<long long int>> edges;
  
};

int main(){
    llint n, m;
    cin >> n >> m;
    vector<pair<long long int, long long int>> v(m);
 
    REP(i,m){
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }
    Graph graph(n,v);
    cout << graph.solve() << endl;
    return 0;
}
