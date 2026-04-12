# LDS最長減少部分列
# 解説放送
# dilworthの定理
# パスを通してどの2点間も移動できないような点集合の点の個数 = 最小パス被覆
# 移動できないような点は
# 右側（大きい値側）から見て以上になっているような数列

from bisect import bisect_right

inf = 10 ** 9 + 1

n = int(input())
a = [int(input()) for _ in range(n)]

t = [inf]
for x in reversed(a):
    if t[-1] <= x:
        t.append(x)
    else:
        insert_pos = bisect_right(t, x)
        t[insert_pos] = x

ret = len(t)

print(ret)
