N = int(input())
K = int(input())

# 桁DP
# 1の位がどの数値かで分岐させていく
#
# 例、F(314, 2)
# 1桁目が0だったらF(31, 2)を合計値に追加
# 1桁目が1~4だったらF(31, 1)を合計値に追加
# 1桁目が5~9だったらF(30, 1)を合計値に追加
# これを再帰させて繰り返していく
# 10以下だったらK==0なら1(10だけ)、K==1ならN個

from functools import lru_cache
@lru_cache(maxsize=None)
def F(N, K):
    assert N >= 0
    if N < 10:
        if K == 0:
            return 1
        if K == 1:
            return N
        return 0
    q, r = divmod(N, 10)
    ret = 0
    # 1の位が0でないときはKを1つ減らして再帰させて追加。Kが1以上でないとできない
    if K >= 1:
        # 10の位以上がそのまま残せるパターン、余りの個数分ある
        ret += F(q, K-1) * r
        # 10の位以上の数を1つ減らすパターン、9 - 余りの個数分ある
        ret += F(q-1, K-1) * (9-r)
    # 1の位が0のときはKそのままで再帰させて追加
    ret += F(q, K)
    return ret

print(F(N, K))
