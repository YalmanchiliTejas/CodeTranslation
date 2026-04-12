# ref: https://atcoder.jp/contests/abc154/submissions/9991364

from functools import lru_cache

#0以上N以下の整数で、0でない数字がちょうどK個あるものの個数
@lru_cache(None)
def F(N, K):
    assert N >= 0
    if N < 10:
        if K == 0:
            return 1
        if K == 1:
            return N
        else:
            return 0
    
    q,r = divmod(N,10)

    ans = 0
    if K >= 1:
        # 1の位が0ではない
        ans += F(q, K-1) * r
        ans += F(q-1, K-1) * (9-r)
    # 1の位が0
    ans += F(q, K)
    
    return ans

def main():
    N = int(input())
    K = int(input())

    print(F(N,K))

if __name__ == "__main__":
    main()