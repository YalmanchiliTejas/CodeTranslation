# reference https://maspypy.com/atcoder-%e5%8f%82%e5%8a%a0%e6%84%9f%e6%83%b3-2019-02-09abc-154
from functools import lru_cache

N = int(input())
K = int(input())


@lru_cache(None)
def F(N, K):
    # print("NK", N, K)
    """N以下で0でないものがちょうどK個。0を含める"""
    # assert N >= 0
    if N < 10:
        if K == 0:
            return 1
        if K == 1:
            return N
        return 0  # 求める数字は作れない
    q, r = divmod(N, 10)
    # print("qr", q, r)
    ret = 0
    if K >= 1:  # 1 の位が nonzero (1 の位で 0 でない数字 を消費するので、第 2 引数は K - 1)
        ret += F(q, K-1) * r  # smaller than 1 の位
        ret += F(q-1, K-1) * (9-r)  # bigger than 1 の位
    ret += F(q, K)  # 1の位が zero (1 の位で 0 でない数字 を消費していないので、第 2 引数は K)
    return ret


print(F(N, K))
