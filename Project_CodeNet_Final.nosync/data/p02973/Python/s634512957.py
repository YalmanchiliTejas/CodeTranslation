import bisect
from collections import deque
N = int(input())
my_max = deque([10 ** 9 + 1])
prev = -1
ans = 0
for _ in range(N):
    a = int(input())
    x = bisect.bisect_left(my_max, a) # a未満
    if x == 0: # どれよりも小さい
        my_max.appendleft(a)
        ans += 1
    else:
        my_max[x - 1] = a # a未満の中で最も大きいものと貪欲に同じ色にする
print(ans)