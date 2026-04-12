from functools import lru_cache
import sys
sys.setrecursionlimit(10**6)


n, x = map(int, input().split())

whole = [1]
putty = [1]
for _ in range(50):
    whole.append(whole[-1] * 2 + 3)
    putty.append(putty[-1] * 2 + 1)


@lru_cache(maxsize=None)
def rec(n, x):
    if n == 0:
        # n == 0のとき、x <= 1なら常にパティ
        return 0 if x < 1 else 1

    # 真ん中で条件分岐する
    med = (whole[n]+1) // 2

    # 真ん中より下なら、1つ前のレベルの結果を少し改造すればよい
    if x < med:
        return rec(n - 1, x - 1)
    # 真ん中なら、1つ前のレベルのパティ総数に1つ足せばよい
    elif x == med:
        return putty[n - 1] + 1
    # 真ん中より上なら、x == medの結果に1つ前のレベルの結果を改造したものを足せばよい
    elif x > med:
        return putty[n - 1] + 1 + rec(n - 1, x - med)


ans = rec(n, x)

print(ans)