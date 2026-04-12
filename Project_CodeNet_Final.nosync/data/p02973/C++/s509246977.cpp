#include <stdio.h>
#include <algorithm>
#include <vector>

template <class Dragons>
class LIS{ // 最長増加部分列を求める
private:
    #define repeat(i, n) for(int (i) = 0; (i) < (n); ++(i))
    #define allRange(A) A.begin(), A.end()

    const int n; // 配列のサイズ
    std::vector<Dragons> V; // 内容本体
    // LongestIncreasingSubsequence[i] := 長さ i の最長増加部分列の末尾の最小要素
    std::vector<Dragons> LongestIncreasingSubsequence;
public:
    // コンストラクタ : vectorを入れる
    LIS(std::vector<Dragons> & VV): n( VV.size() ){ 
        V = VV; LongestIncreasingSubsequence.resize(n+1);
    }
    // コンストラクタ　: 長さ指定
    LIS(int nn): n(nn){ V.resize(nn); LongestIncreasingSubsequence.resize(nn+1);}
    // Vの中身を更新する
    void update(int index, Dragons& element){
        V.at(index) = element;
    }
    // 初期値 : 無限大を入れる
    int compute(Dragons infinity){
        std::fill( allRange(LongestIncreasingSubsequence), infinity);
        repeat(i, n){
            // この要素 : V[i] 未満の最大インデックスを求める : 
            // ただし, 以下の場合は if(LIS[med] '<=' V[i])
            int ok = 0, ng = n + 1;
            while(ng - ok > 1){
                int med = (ok + ng) / 2;
                if(LongestIncreasingSubsequence[med] >= V[i]) ok = med;
                else ng = med;
            }
            LongestIncreasingSubsequence.at(ok+1) = V[i];
        }
        /* 無限大になっていないものを二分探索で検索 */   
        int ok = 0, ng = n + 1;
        while(ng - ok > 1){
            int med = (ok + ng) / 2;
            if(LongestIncreasingSubsequence[med] == infinity) ng = med;
            else ok = med;
        }
        return ok;
    }
    #undef allRange
    #undef repeat
};

int main(void){
    int n; scanf("%d", &n);
    LIS<int> D(n);
    for(int i = 0; i < n; ++i){
      int a; scanf("%d", &a);
      D.update(i, a);
    }
    printf("%d\n", D.compute(-1));
    return 0;
}