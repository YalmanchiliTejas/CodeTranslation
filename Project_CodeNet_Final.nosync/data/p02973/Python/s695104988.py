from collections import deque
import bisect
N = int(input())
l = [int(input()) for _ in range(N)]

# 各色の最大数を保持
colors = deque()
for n in l:
    # 各色の最大数のどれよりも大きくなかったとき色を増やす
    ind = bisect.bisect_left(colors, n)
    if ind == 0:
        colors.appendleft(n)
    else:
        colors[ind-1] = n
print(len(colors))
