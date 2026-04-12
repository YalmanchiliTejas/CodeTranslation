N = int(input())
A = [int(x) for x in input().split(" ")]

from itertools import combinations

mod = 1000000007  # 丁度いい大きさの素数だけで意味は特にない。

s = 0
ans = 0
for n in A:
    s += n
    s %= mod

for i in range(N):
    s -= A[i]
    ans += A[i] * s
    ans %= mod

print(ans)