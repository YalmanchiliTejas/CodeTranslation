import sys

ri = lambda: int(sys.stdin.readline())
rl = lambda: list(map(int, sys.stdin.readline().split()))
mod = 10**9 + 7

n = ri()
a = rl()
s = sum(a)
ans = 0
for i in a:
    s -= i
    ans = (ans + s*i)%mod
print(ans)