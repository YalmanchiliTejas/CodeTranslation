# coding: utf-8
# Your code here!
import sys
readline = sys.stdin.readline
read = sys.stdin.read

n,x,m = map(int, readline().split())
#lr = [list(map(int, readline().split())) for _ in range(k)]


nxt = [x*x%m for x in range(m)]
wa = list(range(m))
ans = 0

while n:
    if n&1:
        ans += wa[x]
        x = nxt[x]
    wa = [wa[nxt[i]] + wa[i] for i in range(m)]    
    nxt = [nxt[i] for i in nxt]
    n >>= 1

print(ans)